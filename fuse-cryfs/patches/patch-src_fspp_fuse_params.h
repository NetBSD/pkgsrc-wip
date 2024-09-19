$NetBSD$

NetBSD provides fuse.h for compat.

--- src/fspp/fuse/params.h.orig	2017-02-11 12:34:50.000000000 +0000
+++ src/fspp/fuse/params.h
@@ -3,7 +3,12 @@
 #define MESSMER_FSPP_FUSE_PARAMS_H_
 
 #define FUSE_USE_VERSION 26
-#ifdef __linux__
+
+#ifdef __NetBSD__
+#define _KMEMUSER 1
+#endif
+
+#if defined(__linux__) || defined(__NetBSD__)
 #include <fuse.h>
 #elif __APPLE__
 #include <osxfuse/fuse.h>
