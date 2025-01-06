$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/web_test/browser/web_test_content_browser_client.h.orig	2024-10-18 12:34:16.217460600 +0000
+++ content/web_test/browser/web_test_content_browser_client.h
@@ -91,6 +91,8 @@ class WebTestContentBrowserClient : publ
                        const std::string& frame_name,
                        WindowOpenDisposition disposition,
                        const blink::mojom::WindowFeatures& features,
+                       const std::string& raw_features,
+                       const scoped_refptr<network::ResourceRequestBody>& body,
                        bool user_gesture,
                        bool opener_suppressed,
                        bool* no_javascript_access) override;
