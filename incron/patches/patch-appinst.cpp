$NetBSD$

Fix build on non-Linux systems.

--- appinst.cpp.orig	2012-04-06 22:19:27.000000000 +0000
+++ appinst.cpp
@@ -26,6 +26,7 @@
 #include <errno.h>
 #include <signal.h>
 #include <cstdio>
+#include <sys/stat.h>
 
 #include "appinst.h"
 
