$NetBSD$

Deal with location of soundcard.h header.

--- alsa.c.orig	2020-03-22 17:43:50.000000000 +0000
+++ alsa.c
@@ -17,7 +17,13 @@
 #include <stdlib.h>             /* for abs() */
 #include <sys/ioctl.h>
 #include <alsa/asoundlib.h>
+
+#if defined(__linux__)
 #include <linux/soundcard.h>
+#elif defined(FreeBSD) || defined(__DragonFly__) || defined (__NetBSD__)
+#include <soundcard.h>
+#endif
+
 #include "xoscope.h"            /* program defaults */
 
 char    alsaDevice[32] = "\0";
