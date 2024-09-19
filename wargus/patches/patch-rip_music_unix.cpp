$NetBSD$

Add NetBSD support.

--- rip_music_unix.cpp.orig	2019-07-06 14:13:14.581553880 -0700
+++ rip_music_unix.cpp	2019-07-06 14:14:56.991326608 -0700
@@ -44,7 +44,7 @@
 #elif defined(__FreeBSD__)
 #	include <sys/param.h>
 #	include <sys/mount.h>
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__NetBSD__)
 #       define __dev_t dev_t
 #       define __ino_t ino_t
 #endif
