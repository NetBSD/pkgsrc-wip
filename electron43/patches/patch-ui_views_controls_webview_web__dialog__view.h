$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/webview/web_dialog_view.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/webview/web_dialog_view.h
@@ -167,8 +167,7 @@ class WEBVIEW_EXPORT WebDialogView : pub
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override;
+      const content::mojom::CreateNewWindowParams& params) override;
   void RequestMediaAccessPermission(
       content::WebContents* web_contents,
       const content::MediaStreamRequest& request,
