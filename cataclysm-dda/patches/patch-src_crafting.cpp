$NetBSD$

Fix includes.

--- src/crafting.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/crafting.cpp
@@ -13,7 +13,7 @@
 #include "messages.h"
 #include "itype.h"
 #include <queue>
-#include <math.h>    //sqrt
+#include <cmath>     //sqrt
 #include <algorithm> //std::min
 
 enum TAB_MODE {
