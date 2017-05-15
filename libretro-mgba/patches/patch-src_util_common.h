$NetBSD$

Needed for strcasecmp

--- src/util/common.h.orig	2017-03-29 18:42:18.000000000 +0000
+++ src/util/common.h
@@ -18,6 +18,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 
 #ifdef _WIN32
 // WinSock2 gets very angry if it's included too late
