$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/browser.cc.orig	2024-10-18 12:34:03.140390400 +0000
+++ chrome/browser/ui/browser.cc
@@ -2069,12 +2069,11 @@ bool Browser::IsWebContentsCreationOverr
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   return window_container_type ==
              content::mojom::WindowContainerType::BACKGROUND &&
          ShouldCreateBackgroundContents(source_site_instance, opener_url,
-                                        frame_name);
+                                        params.frame_name);
 }
 
 WebContents* Browser::CreateCustomWebContents(
