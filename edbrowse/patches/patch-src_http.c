$NetBSD$

Also include <signal.h>, needed for signal(3).

From upstream commit `885fbc5f18ae61f9af9faa3e9d25c67a65148f6a'.

--- src/http.c.orig	2018-03-30 01:25:41.000000000 +0000
+++ src/http.c
@@ -9,6 +9,7 @@
 #include <fcntl.h>
 #else
 #include <sys/wait.h>
+#include <signal.h>
 #endif
 #include <time.h>
 
