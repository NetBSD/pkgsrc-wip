$NetBSD$

WITH_GETLINE patch from FreeBSD ports x11-drivers/xf86-video-intel

--- src/sna/sna_threads.c.orig	2017-02-10 21:52:47.000000000 +0000
+++ src/sna/sna_threads.c
@@ -29,6 +29,11 @@
 #include "config.h"
 #endif
 
+#if defined(__FreeBSD__)
+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+#endif
+
 #include "sna.h"
 
 #include <unistd.h>
