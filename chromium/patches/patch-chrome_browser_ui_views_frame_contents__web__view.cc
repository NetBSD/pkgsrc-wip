$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/contents_web_view.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/views/frame/contents_web_view.cc
@@ -28,7 +28,7 @@
 #include "ui/wm/core/window_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/actor/actor_util.h"  // nogncheck
 #endif
 
@@ -174,7 +174,7 @@ void ContentsWebView::SetWebContents(con
       .Then(&web_modal::WebContentsModalDialogManager::UpdateDialogHost);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ContentsWebView::DidGetUserInteraction(const blink::WebInputEvent& event) {
   // If the user interacts with the web contents, ensure it is activated.
   // This handles cases where the native window does not receive a focus
