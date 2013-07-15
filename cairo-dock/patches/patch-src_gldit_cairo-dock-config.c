$NetBSD: patch-src_gldit_cairo-dock-config.c,v 1.1 2013/07/15 20:14:22 thomasklausner Exp $

No crypt.h on NetBSD either.

--- src/gldit/cairo-dock-config.c.orig	2013-03-23 15:55:12.000000000 +0000
+++ src/gldit/cairo-dock-config.c
@@ -28,7 +28,7 @@
 #include "gldi-config.h"
 
 #ifdef HAVE_LIBCRYPT
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <unistd.h>  // on BSD, there is no crypt.h
 #else
 #include <crypt.h>
