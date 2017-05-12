$NetBSD$

--- disas/libvixl/vixl/utils.h.orig	2017-04-25 12:42:53.000000000 +0000
+++ disas/libvixl/vixl/utils.h
@@ -27,11 +27,12 @@
 #ifndef VIXL_UTILS_H
 #define VIXL_UTILS_H
 
-#include <string.h>
-#include <cmath>
 #include "vixl/globals.h"
 #include "vixl/compiler-intrinsics.h"
 
+#include <string.h>
+#include <cmath>
+
 namespace vixl {
 
 // Macros for compile-time format checking.
