$NetBSD$

--- net/base/address_tracker_linux.h.orig	2020-07-08 21:40:46.000000000 +0000
+++ net/base/address_tracker_linux.h
@@ -6,10 +6,6 @@
 #define NET_BASE_ADDRESS_TRACKER_LINUX_H_
 
 #include <sys/socket.h>  // Needed to include netlink.
-// Mask superfluous definition of |struct net|. This is fixed in Linux 2.6.38.
-#define net net_kernel
-#include <linux/rtnetlink.h>
-#undef net
 #include <stddef.h>
 
 #include <map>
