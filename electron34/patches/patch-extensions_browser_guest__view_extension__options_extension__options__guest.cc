$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/guest_view/extension_options/extension_options_guest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ extensions/browser/guest_view/extension_options/extension_options_guest.cc
@@ -249,8 +249,7 @@ bool ExtensionOptionsGuest::IsWebContent
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   CHECK(!base::FeatureList::IsEnabled(features::kGuestViewMPArch));
 
   // This method handles opening links from within the guest. Since this guest
