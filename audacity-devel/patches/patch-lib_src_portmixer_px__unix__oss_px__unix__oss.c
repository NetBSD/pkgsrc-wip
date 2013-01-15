$NetBSD: patch-lib_src_portmixer_px__unix__oss_px__unix__oss.c,v 1.2 2013/01/15 06:46:48 makoto Exp $

Fix build on sunos.

--- lib-src/portmixer/src/px_unix_oss.c.orig	2012-08-21 17:47:20.000000000 +0900
+++ lib-src/portmixer/src/px_unix_oss.c	2013-01-08 22:25:07.000000000 +0900
@@ -47,6 +47,8 @@
 
 #if defined(HAVE_SYS_SOUNDCARD_H)
 # include <sys/soundcard.h>
+#elif defined(__sun)
+#include <sys/soundcard.h>
 #elif defined(HAVE_LINUX_SOUNDCARD_H)
 # include <linux/soundcard.h>
 #elif defined(HAVE_MACHINE_SOUNDCARD_H)
