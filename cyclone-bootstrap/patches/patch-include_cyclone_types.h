$NetBSD$

Use pkgsrc libtommath instead of cyclone libtommath.

--- include/cyclone/types.h.orig	2024-02-23 20:54:38.634839766 +0000
+++ include/cyclone/types.h
@@ -20,7 +20,7 @@
 #include <pthread.h>
 #include <stdint.h>
 #include <dlfcn.h>
-#include "cyclone/bignum.h"
+#include <tommath.h>
 
 #ifdef CYC_HIGH_RES_TIMERS
 /**
