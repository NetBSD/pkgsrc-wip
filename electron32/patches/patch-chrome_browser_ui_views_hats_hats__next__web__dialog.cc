$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/views/hats/hats_next_web_dialog.cc.orig	2024-10-18 12:34:03.364267000 +0000
+++ chrome/browser/ui/views/hats/hats_next_web_dialog.cc
@@ -75,8 +75,7 @@ class HatsNextWebDialog::HatsWebView : p
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override {
+      const content::mojom::CreateNewWindowParams& params) override {
     return true;
   }
   content::WebContents* CreateCustomWebContents(
