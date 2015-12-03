$NetBSD$

--- main.c.orig	2015-10-22 21:22:34.000000000 +0000
+++ main.c
@@ -2,6 +2,9 @@
 #define _XOPEN_SOURCE
 
 /* for ECHOCTL, ECHOKE, cfsetspeed() */
+#if defined(__NetBSD__)
+# define _NETBSD_SOURCE
+#endif
 #define _BSD_SOURCE
 
 #include <errno.h>
@@ -12,9 +15,11 @@
 
 /* suck up the non-standard openpty/forkpty */
 #if defined(__FreeBSD__)
+# include <sys/ioctl.h>
 # include <libutil.h>
 # include <termios.h>
 #elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
+# include <sys/ioctl.h>
 # include <termios.h>
 # include <util.h>
 #else
