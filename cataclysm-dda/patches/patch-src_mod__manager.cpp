$NetBSD$

Fix includes.

--- src/mod_manager.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/mod_manager.cpp
@@ -5,7 +5,7 @@
 #include "worldfactory.h"
 #include "path_info.h"
 
-#include <math.h>
+#include <cmath>
 #include <queue>
 #include <iostream>
 #include <fstream>
