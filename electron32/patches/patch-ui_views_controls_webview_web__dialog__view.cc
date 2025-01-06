$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/webview/web_dialog_view.cc.orig	2024-10-18 12:35:12.844222500 +0000
+++ ui/views/controls/webview/web_dialog_view.cc
@@ -448,8 +448,7 @@ bool WebDialogView::IsWebContentsCreatio
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   if (delegate_)
     return delegate_->HandleShouldOverrideWebContentsCreation();
   return false;
