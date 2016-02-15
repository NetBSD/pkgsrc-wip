$NetBSD$

--- src/ToolBox/SOS/Strike/eeheap.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/Strike/eeheap.cpp
@@ -8,6 +8,7 @@
 // 
 // ==--==
 #include <assert.h>
+#include <stdlib.h>
 #include "sos.h"
 #include "safemath.h"
 
