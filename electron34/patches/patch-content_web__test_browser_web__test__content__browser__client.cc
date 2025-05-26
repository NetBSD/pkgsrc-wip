$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/web_test/browser/web_test_content_browser_client.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/web_test/browser/web_test_content_browser_client.cc
@@ -521,6 +521,8 @@ bool WebTestContentBrowserClient::CanCre
     const std::string& frame_name,
     WindowOpenDisposition disposition,
     const blink::mojom::WindowFeatures& features,
+    const std::string& raw_features,
+    const scoped_refptr<network::ResourceRequestBody>& body,
     bool user_gesture,
     bool opener_suppressed,
     bool* no_javascript_access) {
