$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/device/usb/usb_service.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/services/device/usb/usb_service.cc
@@ -22,13 +22,17 @@
 
 #if BUILDFLAG(IS_ANDROID)
 #include "services/device/usb/usb_service_android.h"
-#elif defined(USE_UDEV)
+#elif defined(USE_UDEV) && !BUILDFLAG(IS_BSD)
 #include "services/device/usb/usb_service_linux.h"
 #elif BUILDFLAG(IS_MAC)
 #include "services/device/usb/usb_service_impl.h"
 #include "services/device/usb/usb_service_mac.h"
 #elif BUILDFLAG(IS_WIN)
 #include "services/device/usb/usb_service_win.h"
+#elif BUILDFLAG(IS_OPENBSD)
+#include "services/device/usb/usb_service_impl.h"
+#elif BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
+#include "services/device/usb/usb_service_fake.h"
 #endif
 
 namespace device {
@@ -51,7 +55,7 @@ constexpr base::TaskTraits UsbService::k
 std::unique_ptr<UsbService> UsbService::Create() {
 #if BUILDFLAG(IS_ANDROID)
   return base::WrapUnique(new UsbServiceAndroid());
-#elif defined(USE_UDEV)
+#elif defined(USE_UDEV) && !BUILDFLAG(IS_BSD)
   return base::WrapUnique(new UsbServiceLinux());
 #elif BUILDFLAG(IS_WIN)
   return base::WrapUnique(new UsbServiceWin());
@@ -60,6 +64,8 @@ std::unique_ptr<UsbService> UsbService::
     return base::WrapUnique(new UsbServiceMac());
   else
     return base::WrapUnique(new UsbServiceImpl());
+#elif BUILDFLAG(IS_BSD)
+  return base::WrapUnique(new UsbServiceImpl());
 #else
   return nullptr;
 #endif
