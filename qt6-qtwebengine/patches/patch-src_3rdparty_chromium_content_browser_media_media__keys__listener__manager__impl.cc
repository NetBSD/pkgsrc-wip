$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/media/media_keys_listener_manager_impl.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/content/browser/media/media_keys_listener_manager_impl.cc
@@ -299,7 +299,7 @@ void MediaKeysListenerManagerImpl::Start
     return;
   }
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) || \
     BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
