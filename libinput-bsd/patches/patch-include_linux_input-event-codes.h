$NetBSD$

Treat NetBSD line OpenBSD

--- include/linux/input-event-codes.h.orig	2025-08-02 09:40:32.000000000 +0000
+++ include/linux/input-event-codes.h
@@ -1,5 +1,7 @@
 #ifdef __linux__
 #include "linux/input-event-codes.h"
+#elif __NetBSD__
+#include "freebsd/input-event-codes.h"
 #elif __OpenBSD__
 #include "freebsd/input-event-codes.h"
 #elif __FreeBSD__
