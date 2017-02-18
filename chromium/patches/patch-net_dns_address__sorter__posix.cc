$NetBSD$

--- net/dns/address_sorter_posix.cc.orig	2017-02-02 02:02:56.000000000 +0000
+++ net/dns/address_sorter_posix.cc
@@ -13,6 +13,9 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#if defined(OS_FREEBSD)
+#include <net/if_var.h>
+#endif
 #include <netinet/in_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
