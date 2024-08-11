$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/os_integration/shortcut_sub_manager.cc.orig	2024-07-24 02:44:30.408178000 +0000
+++ chrome/browser/web_applications/os_integration/shortcut_sub_manager.cc
@@ -186,7 +186,7 @@ void ShortcutSubManager::Execute(
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Protocol handler update detection. Shortcuts need to be updated in this
   // case on Linux & Mac because the shortcut itself includes the protocol
   // handling metadata.
