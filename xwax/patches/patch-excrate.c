$NetBSD$

Include signal.h for kill(2).

--- excrate.c.orig	2018-01-19 20:40:49.000000000 +0000
+++ excrate.c
@@ -28,6 +28,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <signal.h>
 #include <sys/wait.h>
 
 #include "debug.h"
