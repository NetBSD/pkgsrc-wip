$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/offscreen_tab.cc.orig	2024-10-18 12:34:01.685197800 +0000
+++ chrome/browser/media/offscreen_tab.cc
@@ -286,8 +286,7 @@ bool OffscreenTab::IsWebContentsCreation
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   // Disallow creating separate WebContentses.  The WebContents implementation
   // uses this to spawn new windows/tabs, which is also not allowed for
   // offscreen tabs.
