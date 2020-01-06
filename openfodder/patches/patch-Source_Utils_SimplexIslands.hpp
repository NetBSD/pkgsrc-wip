$NetBSD$

Need stdint.h for int32_t.

--- Source/Utils/SimplexIslands.hpp.orig	2019-12-31 20:48:13.000000000 +0000
+++ Source/Utils/SimplexIslands.hpp
@@ -15,6 +15,7 @@
  *
  */
 #include <math.h>
+#include <stdint.h>
 struct Grad
 {
 	double x, y, z, w;
