$NetBSD$

--- src/audio/AudioFileDevice.cpp.orig	2015-10-03 21:09:58.000000000 +0000
+++ src/audio/AudioFileDevice.cpp
@@ -11,7 +11,7 @@
 #include <assert.h>
 #include <errno.h>
 #include <string.h>
-#if defined(linux) || defined(MACOSX)
+#if defined(linux) || defined(MACOSX) || defined(NETBSD)
 #include <unistd.h>
 #endif
 
