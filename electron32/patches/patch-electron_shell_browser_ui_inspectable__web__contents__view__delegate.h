$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/ui/inspectable_web_contents_view_delegate.h.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/shell/browser/ui/inspectable_web_contents_view_delegate.h
@@ -24,7 +24,7 @@ class InspectableWebContentsViewDelegate
   // Returns the icon of devtools window.
   virtual ui::ImageModel GetDevToolsWindowIcon();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Called when creating devtools window.
   virtual void GetDevToolsWindowWMClass(std::string* name,
                                         std::string* class_name) {}
