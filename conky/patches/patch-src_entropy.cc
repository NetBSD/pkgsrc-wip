$NetBSD$

- Add missing entry for NetBSD.

--- src/entropy.cc.orig	2020-07-27 12:01:52.000000000 +0000
+++ src/entropy.cc
@@ -40,6 +40,8 @@
 #include "freebsd.h"
 #elif defined(__DragonFly__)
 #include "dragonfly.h"
+#elif defined(__NetBSD__)
+#include "netbsd.h"
 #elif defined(__OpenBSD__)
 #include "openbsd.h"
 #elif defined(__sun)
