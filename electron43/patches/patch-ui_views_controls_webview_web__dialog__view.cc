$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/webview/web_dialog_view.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/webview/web_dialog_view.cc
@@ -449,8 +449,7 @@ bool WebDialogView::IsWebContentsCreatio
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   if (delegate_)
     return delegate_->HandleShouldOverrideWebContentsCreation();
   return false;
