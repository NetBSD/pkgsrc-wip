$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/guest_view/extension_options/extension_options_guest.cc.orig	2024-10-18 12:34:17.836640000 +0000
+++ extensions/browser/guest_view/extension_options/extension_options_guest.cc
@@ -218,8 +218,7 @@ bool ExtensionOptionsGuest::IsWebContent
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   // This method handles opening links from within the guest. Since this guest
   // view is used for displaying embedded extension options, we want any
   // external links to be opened in a new tab, not in a new guest view so we
