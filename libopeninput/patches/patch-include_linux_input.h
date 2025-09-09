$NetBSD$

* Add NetBSD support

--- include/linux/input.h.orig	2025-08-17 15:49:37.000000000 +0000
+++ include/linux/input.h
@@ -1,7 +1,5 @@
 #ifdef __linux__
 #include "linux/input.h"
-#elif __OpenBSD__
-#include "freebsd/input.h"
-#elif __FreeBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__)
 #include "freebsd/input.h"
 #endif
