$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/guest_view/app_view/app_view_guest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ extensions/browser/guest_view/app_view/app_view_guest.cc
@@ -153,8 +153,7 @@ bool AppViewGuest::IsWebContentsCreation
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   CHECK(!base::FeatureList::IsEnabled(features::kGuestViewMPArch));
 
   return true;
