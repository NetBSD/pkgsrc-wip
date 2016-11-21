$NetBSD$

Fix includes.

--- src/mtype.h.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/mtype.h
@@ -12,7 +12,7 @@
 #include <string>
 #include <vector>
 #include <set>
-#include <math.h>
+#include <cmath>
 
 class Creature;
 
