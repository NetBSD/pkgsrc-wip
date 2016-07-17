$NetBSD$

--- net/dns/address_sorter_posix.cc.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/dns/address_sorter_posix.cc
@@ -11,6 +11,9 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#if !defined(OS_NETBSD)
+#include <net/if_var.h>
+#endif
 #include <netinet/in_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
