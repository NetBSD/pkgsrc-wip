$NetBSD$

Fix includes.

--- src/overmap.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/overmap.cpp
@@ -1,6 +1,6 @@
 #include <stdlib.h>
-#include <time.h>
-#include <math.h>
+#include <ctime>
+#include <cmath>
 #include <fstream>
 #include <vector>
 #include <sstream>
