$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/chrome_browser_main_linux.cc.orig	2024-10-18 12:34:01.381367400 +0000
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -25,7 +25,7 @@
 #include "device/bluetooth/dbus/bluez_dbus_thread_manager.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
@@ -84,7 +84,9 @@ void ChromeBrowserMainPartsLinux::PostCr
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(nullptr /* system_bus */);
+#endif
 
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
@@ -110,7 +112,7 @@ void ChromeBrowserMainPartsLinux::PostCr
   ChromeBrowserMainPartsPosix::PostCreateMainMessageLoop();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopRun() {
   ChromeBrowserMainPartsPosix::PostMainMessageLoopRun();
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
@@ -169,7 +171,7 @@ void ChromeBrowserMainPartsLinux::CheckI
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // No-op; per PostBrowserStart() comment, this is done elsewhere.
 #else
   bluez::BluezDBusManager::Shutdown();
