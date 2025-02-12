$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/dns/address_sorter_posix.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/net/dns/address_sorter_posix.cc
@@ -27,6 +27,7 @@
 #include "net/dns/netinet_in_var_ios.h"
 #else
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #endif  // BUILDFLAG(IS_IOS)
 #endif
 
