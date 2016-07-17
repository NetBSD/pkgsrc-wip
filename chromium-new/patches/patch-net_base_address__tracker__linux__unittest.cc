$NetBSD$

--- net/base/address_tracker_linux_unittest.cc.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/base/address_tracker_linux_unittest.cc
@@ -13,7 +13,11 @@
 #include "net/base/ip_address.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
+#if defined(__linux__)
 #include <linux/if.h>
+#else
+#include <net/if.h>
+#endif
 
 #ifndef IFA_F_HOMEADDRESS
 #define IFA_F_HOMEADDRESS 0x10
