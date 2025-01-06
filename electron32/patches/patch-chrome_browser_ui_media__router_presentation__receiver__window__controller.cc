$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/media_router/presentation_receiver_window_controller.cc.orig	2024-10-18 12:34:03.176370600 +0000
+++ chrome/browser/ui/media_router/presentation_receiver_window_controller.cc
@@ -203,8 +203,7 @@ bool PresentationReceiverWindowControlle
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   // Disallow creating separate WebContentses.  The WebContents implementation
   // uses this to spawn new windows/tabs, which is also not allowed for
   // local presentations.
