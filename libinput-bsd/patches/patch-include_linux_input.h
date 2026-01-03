$NetBSD$

Treat NetBSD like OpenBSD

--- include/linux/input.h.orig	2025-08-02 09:40:32.000000000 +0000
+++ include/linux/input.h
@@ -1,5 +1,7 @@
 #ifdef __linux__
 #include "linux/input.h"
+#elif __NetBSD__
+#include "freebsd/input.h"
 #elif __OpenBSD__
 #include "freebsd/input.h"
 #elif __FreeBSD__
