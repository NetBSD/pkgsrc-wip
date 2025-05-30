$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/enterprise/signals/device_info_fetcher_linux.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/enterprise/signals/device_info_fetcher_linux.cc
@@ -4,11 +4,22 @@
 
 #include "chrome/browser/enterprise/signals/device_info_fetcher_linux.h"
 
+#include "build/build_config.h"
+
 #if defined(USE_GIO)
 #include <gio/gio.h>
 #endif  // defined(USE_GIO)
 #include <sys/stat.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/sysmacros.h>
+#endif
+
+#if BUILDFLAG(IS_BSD)
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <ifaddrs.h>
+#include <net/if_dl.h>
+#endif
 
 #include <string>
 
@@ -117,6 +128,7 @@ SettingValue GetScreenlockSecured() {
 // Implements the logic from the native host installation script. First find the
 // root device identifier, then locate its parent and get its type.
 SettingValue GetDiskEncrypted() {
+#if !BUILDFLAG(IS_BSD)
   struct stat info;
   // First figure out the device identifier. Fail fast if this fails.
   if (stat("/", &info) != 0)
@@ -138,11 +150,35 @@ SettingValue GetDiskEncrypted() {
     }
     return SettingValue::UNKNOWN;
   }
+#endif
   return SettingValue::DISABLED;
 }
 
 std::vector<std::string> GetMacAddresses() {
   std::vector<std::string> result;
+#if BUILDFLAG(IS_BSD)
+  struct ifaddrs* ifa = nullptr;
+
+  if (getifaddrs(&ifa) != 0)
+    return result;
+
+  struct ifaddrs* interface = ifa;
+  for (; interface != nullptr; interface = interface->ifa_next) {
+    if (interface->ifa_addr == nullptr ||
+        interface->ifa_addr->sa_family != AF_LINK) {
+      continue;
+    }
+    struct sockaddr_dl* sdl =
+        reinterpret_cast<struct sockaddr_dl*>(interface->ifa_addr);
+    if (!sdl || sdl->sdl_alen != 6)
+      continue;
+    char* link_address = static_cast<char*>(LLADDR(sdl));
+    result.push_back(base::StringPrintf(
+        "%02x:%02x:%02x:%02x:%02x:%02x", link_address[0] & 0xff,
+        link_address[1] & 0xff, link_address[2] & 0xff, link_address[3] & 0xff,
+        link_address[4] & 0xff, link_address[5] & 0xff));
+  }
+#else
   base::DirReaderPosix reader("/sys/class/net");
   if (!reader.IsValid())
     return result;
@@ -165,6 +201,7 @@ std::vector<std::string> GetMacAddresses
                               &address);
     result.push_back(address);
   }
+#endif
   return result;
 }
 
