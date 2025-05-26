$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/web_contents_delegate.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/web_contents_delegate.cc
@@ -31,6 +31,17 @@ namespace content {
 
 WebContentsDelegate::WebContentsDelegate() = default;
 
+void WebContentsDelegate::WebContentsCreatedWithFullParams(
+    WebContents* source_contents,
+    int opener_render_process_id,
+    int opener_render_frame_id,
+    const mojom::CreateNewWindowParams& params,
+    WebContents* new_contents) {
+  WebContentsCreated(source_contents, opener_render_process_id,
+                     opener_render_frame_id, params.frame_name,
+                     params.target_url, new_contents);
+}
+
 WebContents* WebContentsDelegate::OpenURLFromTab(
     WebContents* source,
     const OpenURLParams& params,
@@ -141,8 +152,7 @@ bool WebContentsDelegate::IsWebContentsC
     SiteInstance* source_site_instance,
     mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const mojom::CreateNewWindowParams& params) {
   return false;
 }
 
