$NetBSD: patch-build_src_glbuild.c,v 1.1 2015/08/19 20:36:32 yhardy Exp $

Search for correctl libGL on NetBSD.

--- build/src/glbuild.c.orig	2015-07-15 08:23:00.000000000 +0000
+++ build/src/glbuild.c
@@ -379,7 +379,7 @@ int32_t loadgldriver(const char *driver)
         driver = "opengl32.dll";
 #elif defined EDUKE32_OSX
         driver = "/System/Library/Frameworks/OpenGL.framework/OpenGL";
-#elif defined __OpenBSD__
+#elif defined __OpenBSD__ || defined __NetBSD__
         driver = "libGL.so";
 #else
         driver = "libGL.so.1";
@@ -1061,7 +1061,7 @@ int32_t loadglulibrary(const char *drive
         driver = "glu32.dll";
 #elif defined __APPLE__
         driver = "/System/Library/Frameworks/OpenGL.framework/OpenGL"; // FIXME: like I know anything about Apple.  Hah.
-#elif defined __OpenBSD__
+#elif defined __OpenBSD__ || defined __NetBSD__
         driver = "libGLU.so";
 #else
         driver = "libGLU.so.1";
