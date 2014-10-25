$NetBSD: patch-src_applets_volume.c,v 1.1 2014/10/25 00:00:42 khorben Exp $

Fix SunOS includes.

--- src/applets/volume.c.orig	2014-05-16 19:42:45.000000000 +0000
+++ src/applets/volume.c
@@ -19,7 +19,7 @@
 
 
 #include <sys/ioctl.h>
-#if defined(__NetBSD__) || defined(__sun__)
+#if defined(__NetBSD__)
 # include <sys/audioio.h>
 #elif defined(__linux__)
 # include <alsa/asoundlib.h>
