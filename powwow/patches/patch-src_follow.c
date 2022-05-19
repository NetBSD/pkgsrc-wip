$NetBSD$

--- src/follow.c.orig	2022-05-19 18:04:39.773135287 +0200
+++ src/follow.c	2022-05-19 18:05:38.948865876 +0200
@@ -43,6 +43,7 @@
 
 #ifdef BSD_LIKE
 # include <sys/ioctl_compat.h>
+# include <sys/termios.h>
 # define O_RAW RAW
 # define O_ECHO ECHO
 # define O_CBREAK CBREAK
