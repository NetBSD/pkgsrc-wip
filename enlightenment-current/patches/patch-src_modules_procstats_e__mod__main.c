$NetBSD$

--- src/modules/procstats/e_mod_main.c.orig	2023-12-23 16:08:09.000000000 +0000
+++ src/modules/procstats/e_mod_main.c
@@ -1,7 +1,7 @@
 # include <e.h>
 #include "process.h"
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 # include <sys/types.h>
 # include <sys/sysctl.h>
 #endif
