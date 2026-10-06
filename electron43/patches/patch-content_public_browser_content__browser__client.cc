$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/content_browser_client.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/content_browser_client.cc
@@ -785,6 +785,8 @@ bool ContentBrowserClient::CanCreateWind
     const std::string& frame_name,
     WindowOpenDisposition disposition,
     const blink::mojom::WindowFeatures& features,
+    const std::string& raw_features,
+    const scoped_refptr<network::ResourceRequestBody>& body,
     bool user_gesture,
     bool opener_suppressed,
     bool* no_javascript_access) {
@@ -1355,7 +1357,7 @@ bool ContentBrowserClient::ShouldRunOutO
 // that can be adequately sandboxed.
 // Currently Android's network service will not run out of process or sandboxed,
 // so OutOfProcessSystemDnsResolution is not currently enabled on Android.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
