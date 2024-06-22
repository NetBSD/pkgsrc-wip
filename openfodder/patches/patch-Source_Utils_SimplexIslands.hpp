$NetBSD$

Include sys/types.h for size_t.

--- Source/Utils/SimplexIslands.hpp.orig	2024-06-22 09:41:36.108132033 +0000
+++ Source/Utils/SimplexIslands.hpp
@@ -16,6 +16,7 @@
  */
 #include <math.h>
 #include <stdint.h>
+#include <sys/types.h>
 struct Grad
 {
 	double x, y, z, w;
