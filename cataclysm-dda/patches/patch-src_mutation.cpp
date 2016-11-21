$NetBSD$

Fix includes.

--- src/mutation.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/mutation.cpp
@@ -8,7 +8,7 @@
 #include "overmapbuffer.h"
 #include "sounds.h"
 
-#include <math.h>    //sqrt
+#include <cmath>     //sqrt
 #include <algorithm> //std::min
 #include <sstream>
 
