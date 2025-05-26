$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/browser.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/browser.cc
@@ -2145,12 +2145,11 @@ bool Browser::IsWebContentsCreationOverr
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
