$NetBSD$

Fix includes.

--- src/line.h.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/line.h
@@ -4,7 +4,7 @@
 #include <vector>
 #include <string>
 #include "enums.h"
-#include <math.h>
+#include <cmath>
 
 enum direction {
     NORTH = 0,
