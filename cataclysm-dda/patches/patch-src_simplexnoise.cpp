$NetBSD$

Fix includes.

--- src/simplexnoise.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/simplexnoise.cpp
@@ -16,7 +16,7 @@
  */
 
 
-#include <math.h>
+#include <cmath>
 
 #include "simplexnoise.h"
 
