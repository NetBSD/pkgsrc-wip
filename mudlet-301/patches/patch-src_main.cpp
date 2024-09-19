$NetBSD$
Swap out /usr/local with @PREFIX@
--- src/main.cpp.orig	2017-07-11 00:01:53.000000000 +0000
+++ src/main.cpp
@@ -36,7 +36,7 @@
 #include "post_guard.h"
 
 
-// N/U: #define MUDLET_HOME "/usr/local/share/mudlet/"
+// N/U: #define MUDLET_HOME "@PREFIX@/share/mudlet/"
 
 using namespace std;
 
