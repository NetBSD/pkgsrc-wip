$NetBSD$

Needed for signal(3).

--- src/http.c.orig	2018-03-30 01:25:41.000000000 +0000
+++ src/http.c
@@ -10,6 +10,7 @@
 #else
 #include <sys/wait.h>
 #endif
+#include <signal.h>
 #include <time.h>
 
 char *serverData;
