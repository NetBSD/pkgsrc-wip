$NetBSD$

# Support non-x86 platforms with SIMDE

--- ksw.c.orig	2022-03-17 13:43:27.000000000 +0000
+++ ksw.c
@@ -26,7 +26,8 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
-#include <emmintrin.h>
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 #include "ksw.h"
 
 #ifdef __GNUC__
