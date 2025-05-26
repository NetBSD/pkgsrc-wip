$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/web_test/browser/web_test_content_browser_client.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/web_test/browser/web_test_content_browser_client.h
@@ -92,6 +92,8 @@ class WebTestContentBrowserClient : publ
                        const std::string& frame_name,
                        WindowOpenDisposition disposition,
                        const blink::mojom::WindowFeatures& features,
+                       const std::string& raw_features,
+                       const scoped_refptr<network::ResourceRequestBody>& body,
                        bool user_gesture,
                        bool opener_suppressed,
                        bool* no_javascript_access) override;
