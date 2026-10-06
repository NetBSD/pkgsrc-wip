$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/media/multi_buffer_data_source.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/media/multi_buffer_data_source.cc
@@ -13,8 +13,10 @@
 #include "base/functional/callback_helpers.h"
 #include "base/location.h"
 #include "base/memory/raw_ptr.h"
+#include "base/no_destructor.h"
 #include "base/numerics/safe_conversions.h"
 #include "base/task/single_thread_task_runner.h"
+#include "base/strings/string_util.h"
 #include "media/base/media_log.h"
 #include "net/base/net_errors.h"
 #include "third_party/blink/renderer/platform/media/buffered_data_source_host_impl.h"
@@ -63,8 +65,20 @@ const int kUpdateBufferSizeFrequency = 3
 // How long to we delay a seek after a read?
 constexpr base::TimeDelta kSeekDelay = base::Milliseconds(20);
 
+std::vector<std::string>* GetStreamingSchemes() {
+  static base::NoDestructor<std::vector<std::string>> streaming_schemes({
+    url::kHttpsScheme,
+    url::kHttpScheme
+  });
+  return streaming_schemes.get();
+}
+
 }  // namespace
 
+void AddStreamingScheme(const char* new_scheme) {
+  GetStreamingSchemes()->push_back(new_scheme);
+}
+
 class MultiBufferDataSource::ReadOperation {
  public:
   ReadOperation() = delete;
@@ -156,7 +170,14 @@ bool MultiBufferDataSource::media_has_pl
 
 bool MultiBufferDataSource::AssumeFullyBuffered() const {
   DCHECK(url_data_);
-  return !url_data_->url().ProtocolIsInHTTPFamily();
+
+  const std::string scheme = url_data_->url().Protocol().Ascii();
+  for (const std::string& streaming_scheme : *GetStreamingSchemes()) {
+    if (base::EqualsCaseInsensitiveASCII(scheme, streaming_scheme)) {
+      return false;
+    }
+  }
+  return true;
 }
 
 void MultiBufferDataSource::SetReader(
