$NetBSD: patch-base_third__party_nspr_prcpucfg.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- base/third_party/nspr/prcpucfg.h.orig	2011-05-24 08:01:33.000000000 +0000
+++ base/third_party/nspr/prcpucfg.h
@@ -36,8 +36,10 @@
 #include "base/third_party/nspr/prcpucfg_mac.h"
 #elif defined(__linux__) || defined(__native_client__)
 #include "base/third_party/nspr/prcpucfg_linux.h"
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include "base/third_party/nspr/prcpucfg_freebsd.h"
+#elif defined(__NetBSD__)
+#include "base/third_party/nspr/prcpucfg_netbsd.h"
 #elif defined(__OpenBSD__)
 #include "base/third_party/nspr/prcpucfg_openbsd.h"
 #elif defined(__sun)
