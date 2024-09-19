$NetBSD$

Include signal.h for kill(2).

--- track.c.orig	2018-01-19 20:40:49.000000000 +0000
+++ track.c
@@ -21,6 +21,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <signal.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/mman.h> /* mlock() */
