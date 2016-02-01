# HG changeset patch
# User Landry Breuil <landry@openbsd.org>
# Date 1454101563 0
#      Fri Jan 29 21:06:03 2016 +0000
# Node ID 91d69babe26a073e195768359a94cd7518be1d1c
# Parent  50b6f681c7ed32eb71fdfc9d4583b7ad1fda18c8
Bug 1243493 - Add BSDs to NSPR moz.build. r?ted

diff --git a/config/external/nspr/prcpucfg.h b/config/external/nspr/prcpucfg.h
--- config/external/nspr/prcpucfg.h
+++ config/external/nspr/prcpucfg.h
@@ -9,15 +9,21 @@
 /*
  * Need to support conditionals that are defined in both the top-level build
  * system as well as NSS' build system for now.
  */
 #if defined(XP_DARWIN) || defined(DARWIN)
 #include "md/_darwin.cfg"
 #elif defined(XP_WIN) || defined(_WINDOWS)
 #include "md/_win95.cfg"
+#elif defined(__FreeBSD__)
+#include "md/_freebsd.cfg"
+#elif defined(__NetBSD__)
+#include "md/_netbsd.cfg"
+#elif defined(__OpenBSD__)
+#include "md/_openbsd.cfg"
 #elif defined(__linux__)
 #include "md/_linux.cfg"
 #else
 #error "Unsupported platform!"
 #endif
 
 #endif /* NSPR_PRCPUCFG_H_ */
