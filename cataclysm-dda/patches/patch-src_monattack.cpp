$NetBSD$

Fix includes.

--- src/monattack.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/monattack.cpp
@@ -16,8 +16,8 @@
 #include <algorithm>
 
 //Used for e^(x) functions
-#include <stdio.h>
-#include <math.h>
+#include <cstdio>
+#include <cmath>
 
 // for loading monster dialogue:
 #include <iostream>
