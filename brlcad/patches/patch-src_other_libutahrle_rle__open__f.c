$NetBSD$

For some reason HAVE_UNISTD_H and HAVE_SYS_WAIT_H are undefined.
Add NetBSD support.

--- src/other/libutahrle/rle_open_f.c.orig	2016-08-09 06:47:00.000000000 +0000
+++ src/other/libutahrle/rle_open_f.c
@@ -12,14 +12,14 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#ifdef HAVE_UNISTD_H
+#if 1 /* def HAVE_UNISTD_H */
 #  include <unistd.h>
 #endif
 
 #ifndef NO_OPEN_PIPES
 /* Need to have a SIGCLD signal catcher. */
 #include <signal.h>
-#ifdef HAVE_SYS_WAIT_H
+#if 1 /* def HAVE_SYS_WAIT_H */
 #  include <sys/wait.h>
 #endif
 #include <errno.h>
