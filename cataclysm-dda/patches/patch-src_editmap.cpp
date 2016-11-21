$NetBSD$

Fix includes.

--- src/editmap.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/editmap.cpp
@@ -23,7 +23,7 @@
 #include <set>
 #include <algorithm>
 #include <string>
-#include <math.h>
+#include <cmath>
 #include <vector>
 #include <cstdlib>
 #include "debug.h"
