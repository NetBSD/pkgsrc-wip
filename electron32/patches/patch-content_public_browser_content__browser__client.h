$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/content_browser_client.h.orig	2024-10-18 12:34:14.394394000 +0000
+++ content/public/browser/content_browser_client.h
@@ -189,6 +189,7 @@ class NetworkService;
 class TrustedURLLoaderHeaderClient;
 }  // namespace mojom
 struct ResourceRequest;
+class ResourceRequestBody;
 }  // namespace network
 
 namespace sandbox {
@@ -328,6 +329,11 @@ class CONTENT_EXPORT ContentBrowserClien
 
   virtual ~ContentBrowserClient() = default;
 
+  // Electron: Registers a pending site instance during a navigation.
+  virtual void RegisterPendingSiteInstance(
+      content::RenderFrameHost* rfh,
+      content::SiteInstance* pending_site_instance) {}
+
   // Allows the embedder to set any number of custom BrowserMainParts
   // implementations for the browser startup code. See comments in
   // browser_main_parts.h.
@@ -1285,6 +1291,8 @@ class CONTENT_EXPORT ContentBrowserClien
       const std::string& frame_name,
       WindowOpenDisposition disposition,
       const blink::mojom::WindowFeatures& features,
+      const std::string& raw_features,
+      const scoped_refptr<network::ResourceRequestBody>& body,
       bool user_gesture,
       bool opener_suppressed,
       bool* no_javascript_access);
