$NetBSD: patch-base_third__party_nspr_prcpucfg.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/third_party/nspr/prcpucfg.h.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/third_party/nspr/prcpucfg.h
@@ -36,9 +36,9 @@
 #include "base/third_party/nspr/prcpucfg_mac.h"
 #elif defined(__linux__) || defined(__native_client__)
 #include "base/third_party/nspr/prcpucfg_linux.h"
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include "base/third_party/nspr/prcpucfg_freebsd.h"
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 #include "base/third_party/nspr/prcpucfg_openbsd.h"
 #elif defined(__sun)
 #include "base/third_party/nspr/prcpucfg_solaris.h"
