$NetBSD$

There's no reason to not always include assert.h when using assert.

--- idlib/math/Math.h.orig	2019-02-02 17:51:35.000000000 +0000
+++ idlib/math/Math.h
@@ -27,18 +27,14 @@
 
 #include "../../sys/sys_public.h"
 
-#ifdef __linux__
 #include <cassert>
 #include <float.h> // for FLT_MIN and FLT_MAX #3867
-#endif
 
 #ifdef MACOS_X
 #ifdef __ppc__
 // for square root estimate instruction
 #include <ppc_intrinsics.h>
 #endif
-// for FLT_MIN
-#include <float.h>
 #endif
 /*
 ===============================================================================
