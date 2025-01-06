$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/device/hid/hid_service.cc.orig	2024-10-18 12:34:32.041744000 +0000
+++ services/device/hid/hid_service.cc
@@ -20,11 +20,15 @@
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_UDEV)
 #include "services/device/hid/hid_service_linux.h"
+#elif BUILDFLAG(IS_OPENBSD)
+#include "services/device/hid/hid_service_fido.h"
+#elif BUILDFLAG(IS_FREEBSD)
+#include "services/device/hid/hid_service_freebsd.h"
 #elif BUILDFLAG(IS_MAC)
 #include "services/device/hid/hid_service_mac.h"
 #elif BUILDFLAG(IS_WIN)
 #include "services/device/hid/hid_service_win.h"
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_NETBSD)
 #include "services/device/hid/hid_service_fuchsia.h"
 #endif
 
@@ -68,6 +72,10 @@ constexpr base::TaskTraits HidService::k
 std::unique_ptr<HidService> HidService::Create() {
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_UDEV)
   return std::make_unique<HidServiceLinux>();
+#elif BUILDFLAG(IS_OPENBSD)
+  return std::make_unique<HidServiceFido>();
+#elif BUILDFLAG(IS_FREEBSD)
+  return std::make_unique<HidServiceFreeBSD>();
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<HidServiceMac>();
 #elif BUILDFLAG(IS_WIN)
