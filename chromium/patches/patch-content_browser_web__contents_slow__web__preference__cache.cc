$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/web_contents/slow_web_preference_cache.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ content/browser/web_contents/slow_web_preference_cache.cc
@@ -17,7 +17,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "ui/events/devices/input_device_observer_win.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/events/devices/device_data_manager.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "ui/base/device_form_factor.h"
@@ -57,7 +57,7 @@ SlowWebPreferenceCache::SlowWebPreferenc
 
 #if BUILDFLAG(IS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->AddObserver(this);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ui::DeviceDataManager::GetInstance()->AddObserver(this);
 #elif BUILDFLAG(IS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->AddObserver(this);
@@ -69,7 +69,7 @@ SlowWebPreferenceCache::SlowWebPreferenc
 SlowWebPreferenceCache::~SlowWebPreferenceCache() {
 #if BUILDFLAG(IS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->RemoveObserver(this);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ui::DeviceDataManager::GetInstance()->RemoveObserver(this);
 #elif BUILDFLAG(IS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->RemoveObserver(this);
