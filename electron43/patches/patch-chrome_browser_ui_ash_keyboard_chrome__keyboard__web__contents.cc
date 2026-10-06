$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/ash/keyboard/chrome_keyboard_web_contents.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/ash/keyboard/chrome_keyboard_web_contents.cc
@@ -79,8 +79,7 @@ class ChromeKeyboardContentsDelegate : p
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override {
+      const content::mojom::CreateNewWindowParams& params) override {
     return true;
   }
 
