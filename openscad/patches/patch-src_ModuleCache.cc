$NetBSD$

--- src/ModuleCache.cc.orig	2018-03-13 12:12:43.000000000 +0000
+++ src/ModuleCache.cc
@@ -10,6 +10,7 @@
 #include <fstream>
 #include <sstream>
 #include <time.h>
+#include <sys/timeb.h>
 #include <sys/stat.h>
 #include <algorithm>
 
