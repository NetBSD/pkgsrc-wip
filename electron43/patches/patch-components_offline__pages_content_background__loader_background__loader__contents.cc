$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/offline_pages/content/background_loader/background_loader_contents.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/offline_pages/content/background_loader/background_loader_contents.cc
@@ -89,8 +89,7 @@ bool BackgroundLoaderContents::IsWebCont
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   // Background pages should not create other webcontents/tabs.
   return true;
 }
