$NetBSD$

Fix includes.

--- src/bionics.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/bionics.cpp
@@ -10,7 +10,7 @@
 #include "overmapbuffer.h"
 #include "sounds.h"
 
-#include <math.h>    //sqrt
+#include <cmath>     //sqrt
 #include <algorithm> //std::min
 #include <sstream>
 
