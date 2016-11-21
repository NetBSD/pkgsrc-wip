$NetBSD$

Fix includes.

--- src/monmove.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/monmove.cpp
@@ -12,10 +12,10 @@
 #include "monattack.h"
 #include "monstergenerator.h"
 
-#include <stdlib.h>
+#include <cstdlib>
 //Used for e^(x) functions
-#include <stdio.h>
-#include <math.h>
+#include <cstdio>
+#include <cmath>
 
 #define MONSTER_FOLLOW_DIST 8
 
