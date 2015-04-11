$NetBSD: patch-plugin-volume_ossengine.cpp,v 1.1 2015/04/11 15:56:24 krytarowski Exp $

Fix NetBSD build

sys/soundcard.h is an OSS (Linux) audio emulator

Patch merged upstream
https://github.com/lxde/lxqt-panel/pull/165

--- plugin-volume/ossengine.cpp.orig	2015-02-08 09:31:27.000000000 +0000
+++ plugin-volume/ossengine.cpp
@@ -36,7 +36,7 @@
 #include <sys/ioctl.h>
 #include <errno.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/soundcard.h>
 #elif defined(__linux__) || defined(__Linux__)
 #include <linux/soundcard.h>
