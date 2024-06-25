$NetBSD$

# Unpoison macros on NetBSD

--- gcc/tree.cc.orig	2024-06-24 19:45:22.968928884 +0000
+++ gcc/tree.cc
@@ -28,6 +28,7 @@ along with GCC; see the file COPYING3.  
    calls language-dependent routines.  */
 
 #include "config.h"
+#include "escaped_string.h"
 #include "system.h"
 #include "coretypes.h"
 #include "backend.h"
@@ -67,7 +68,6 @@ along with GCC; see the file COPYING3.  
 #include "regs.h"
 #include "tree-vector-builder.h"
 #include "gimple-fold.h"
-#include "escaped_string.h"
 #include "gimple-range.h"
 #include "gomp-constants.h"
 #include "dfp.h"
