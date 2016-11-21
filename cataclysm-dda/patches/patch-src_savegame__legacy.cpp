$NetBSD$

Fix includes.

--- src/savegame_legacy.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/savegame_legacy.cpp
@@ -44,7 +44,7 @@
 #include <string>
 #include <fstream>
 #include <sstream>
-#include <math.h>
+#include <cmath>
 #include <vector>
 
 #define ARRAY_SIZE(array) ( sizeof( array ) / sizeof( array[0] ) )
