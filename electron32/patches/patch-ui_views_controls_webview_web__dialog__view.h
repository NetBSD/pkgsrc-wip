$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/webview/web_dialog_view.h.orig	2024-10-18 12:35:12.844222500 +0000
+++ ui/views/controls/webview/web_dialog_view.h
@@ -165,8 +165,7 @@ class WEBVIEW_EXPORT WebDialogView : pub
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override;
+      const content::mojom::CreateNewWindowParams& params) override;
   void RequestMediaAccessPermission(
       content::WebContents* web_contents,
       const content::MediaStreamRequest& request,
