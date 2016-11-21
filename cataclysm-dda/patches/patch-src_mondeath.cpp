$NetBSD$

Fix includes.

--- src/mondeath.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/mondeath.cpp
@@ -8,7 +8,7 @@
 #include "sounds.h"
 #include "mondeath.h"
 
-#include <math.h>  // rounding
+#include <cmath>  // rounding
 #include <sstream>
 
 void mdeath::normal(monster *z)
