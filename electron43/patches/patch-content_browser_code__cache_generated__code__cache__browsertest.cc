$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/code_cache/generated_code_cache_browsertest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/code_cache/generated_code_cache_browsertest.cc
@@ -11,17 +11,22 @@
 #include "base/time/time.h"
 #include "content/browser/code_cache/generated_code_cache_context.h"
 #include "content/browser/renderer_host/code_cache_host_impl.h"
+#include "content/browser/storage_partition_impl.h"
 #include "content/browser/web_contents/web_contents_impl.h"
 #include "content/common/renderer.mojom.h"
+#include "content/common/url_schemes.h"
 #include "content/public/browser/browser_context.h"
+#include "content/public/browser/browser_thread.h"
 #include "content/public/browser/render_process_host.h"
 #include "content/public/browser/storage_partition.h"
 #include "content/public/test/browser_test.h"
 #include "content/public/test/browser_test_utils.h"
 #include "content/public/test/content_browser_test.h"
 #include "content/public/test/content_browser_test_utils.h"
+#include "content/public/test/test_browser_context.h"
 #include "content/shell/browser/shell.h"
 #include "content/test/content_browser_test_utils_internal.h"
+#include "content/test/test_content_client.h"
 #include "net/dns/mock_host_resolver.h"
 #include "third_party/blink/public/common/features.h"
 #include "third_party/blink/public/common/page/v8_compile_hints_histograms.h"
@@ -30,6 +35,8 @@ namespace content {
 
 namespace {
 
+const std::string kCodeCacheScheme = "test-code-cache";
+
 bool SupportsSharedWorker() {
 #if BUILDFLAG(IS_ANDROID)
   // SharedWorkers are not enabled on Android. https://crbug.com/154571
@@ -875,4 +882,82 @@ IN_PROC_BROWSER_TEST_F(LocalCompileHints
   }
 }
 
+class CodeCacheInCustomSchemeBrowserTest : public ContentBrowserTest,
+                                           public TestContentClient {
+ public:
+  CodeCacheInCustomSchemeBrowserTest() {
+    SetContentClient(this);
+    ReRegisterContentSchemesForTests();
+  }
+
+  ~CodeCacheInCustomSchemeBrowserTest() override { SetContentClient(nullptr); }
+
+ private:
+  void AddAdditionalSchemes(Schemes* schemes) override {
+    schemes->standard_schemes.push_back(kCodeCacheScheme);
+    schemes->code_cache_schemes.push_back(kCodeCacheScheme);
+  }
+
+  url::ScopedSchemeRegistryForTests scheme_registry_;
+};
+
+IN_PROC_BROWSER_TEST_F(CodeCacheInCustomSchemeBrowserTest,
+                       AllowedCustomSchemeCanGenerateCodeCache) {
+  StoragePartitionImpl* partition =
+      static_cast<StoragePartitionImpl*>(shell()
+                                             ->web_contents()
+                                             ->GetBrowserContext()
+                                             ->GetDefaultStoragePartition());
+  scoped_refptr<GeneratedCodeCacheContext> context =
+      partition->GetGeneratedCodeCacheContext();
+  EXPECT_NE(context, nullptr);
+
+  GURL url(kCodeCacheScheme + "://host4/script.js");
+  GURL origin(kCodeCacheScheme + "://host1:1/");
+  ASSERT_TRUE(url.is_valid());
+  ASSERT_TRUE(origin.is_valid());
+  std::string data("SomeData");
+
+  // Add a code cache entry for the custom scheme.
+  base::test::TestFuture<void> add_entry_future;
+  GeneratedCodeCacheContext::RunOrPostTask(
+      context.get(), FROM_HERE,
+      base::BindOnce(
+          [](scoped_refptr<GeneratedCodeCacheContext> context, const GURL& url,
+             const GURL& origin, const std::string& data,
+             base::OnceClosure callback) {
+            context->generated_js_code_cache()->WriteEntry(
+                url, origin, net::NetworkIsolationKey(), base::Time::Now(),
+                std::vector<uint8_t>(data.begin(), data.end()));
+            GetUIThreadTaskRunner({})->PostTask(FROM_HERE, std::move(callback));
+          },
+          context, url, origin, data, add_entry_future.GetCallback()));
+  ASSERT_TRUE(add_entry_future.Wait());
+
+  // Get the code cache entry.
+  base::test::TestFuture<std::string> get_entry_future;
+  GeneratedCodeCacheContext::RunOrPostTask(
+      context.get(), FROM_HERE,
+      base::BindOnce(
+          [](scoped_refptr<GeneratedCodeCacheContext> context, const GURL& url,
+             const GURL& origin,
+             base::OnceCallback<void(std::string)> callback) {
+            context->generated_js_code_cache()->FetchEntry(
+                url, origin, net::NetworkIsolationKey(),
+                base::BindOnce(
+                    [](base::OnceCallback<void(std::string)> callback,
+                       const base::Time& response_time,
+                       mojo_base::BigBuffer buffer) {
+                      std::string data(buffer.data(),
+                                       buffer.data() + buffer.size());
+                      GetUIThreadTaskRunner({})->PostTask(
+                          FROM_HERE, base::BindOnce(std::move(callback), data));
+                    },
+                    std::move(callback)));
+          },
+          context, url, origin, get_entry_future.GetCallback()));
+  ASSERT_TRUE(get_entry_future.Wait());
+  ASSERT_EQ(data, get_entry_future.Get<0>());
+}
+
 }  // namespace content
