$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/guest_view/mime_handler_view/mime_handler_view_guest.cc.orig	2024-10-18 12:34:17.840638000 +0000
+++ extensions/browser/guest_view/mime_handler_view/mime_handler_view_guest.cc
@@ -389,8 +389,7 @@ bool MimeHandlerViewGuest::IsWebContents
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   return true;
 }
 
