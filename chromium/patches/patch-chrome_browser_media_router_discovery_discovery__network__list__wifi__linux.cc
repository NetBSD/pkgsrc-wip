$NetBSD$

--- chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc
@@ -9,7 +9,9 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 
+#if defined(OS_LINUX)
 #include <linux/wireless.h>
+#endif
 
 #include "base/check.h"
 #include "base/files/scoped_file.h"
@@ -20,6 +22,7 @@ namespace media_router {
 bool MaybeGetWifiSSID(const std::string& if_name, std::string* ssid_out) {
   DCHECK(ssid_out);
 
+#if !defined(OS_BSD)
   base::ScopedFD ioctl_socket(socket(AF_INET, SOCK_DGRAM, 0));
   if (!ioctl_socket.is_valid()) {
     // AF_INET is for IPv4, so it may fail for IPv6-only hosts even when there
@@ -41,6 +44,7 @@ bool MaybeGetWifiSSID(const std::string&
     ssid_out->assign(ssid);
     return true;
   }
+#endif
   return false;
 }
 
