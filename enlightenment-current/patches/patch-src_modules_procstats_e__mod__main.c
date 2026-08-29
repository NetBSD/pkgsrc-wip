$NetBSD$

Merged upstream: https://git.enlightenment.org/enlightenment/enlightenment/pulls/139
The PR also introduces a new (NetBSD) upstream change to e_mod_main.c,
but the relevant code is not existing in enlightenment 0.27.1 yet,
therefore no extra changes are required for this patch.

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
