$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/offline_pages/content/background_loader/background_loader_contents.cc.orig	2024-10-18 12:34:06.918329700 +0000
+++ components/offline_pages/content/background_loader/background_loader_contents.cc
@@ -85,8 +85,7 @@ bool BackgroundLoaderContents::IsWebCont
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   // Background pages should not create other webcontents/tabs.
   return true;
 }
