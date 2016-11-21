$NetBSD$

Fix includes.

--- src/savegame.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/savegame.cpp
@@ -23,7 +23,7 @@
 #include <string>
 #include <fstream>
 #include <sstream>
-#include <math.h>
+#include <cmath>
 #include <vector>
 #include "debug.h"
 #include "weather.h"
