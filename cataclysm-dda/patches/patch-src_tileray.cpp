$NetBSD$

Fix includes.

--- src/tileray.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/tileray.cpp
@@ -1,7 +1,7 @@
 #include "tileray.h"
 #include "game_constants.h"
-#include <math.h>
-#include <stdlib.h>
+#include <cmath>
+#include <cstdlib>
 
 static const int sx[4] = { 1, -1, -1, 1 };
 static const int sy[4] = { 1, 1, -1, -1 };
