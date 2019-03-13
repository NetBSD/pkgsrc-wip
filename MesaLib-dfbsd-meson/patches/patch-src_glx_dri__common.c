$NetBSD$

--- src/glx/dri_common.c.orig	2019-03-06 23:05:20.000000000 +0000
+++ src/glx/dri_common.c
@@ -73,6 +73,10 @@ dri_message(int level, const char *f, ..
    }
 }
 
+#if defined(SO_NAME_OPENBSD)
+#define GL_LIB_NAME "libGL.so"
+#endif
+
 #ifndef GL_LIB_NAME
 #define GL_LIB_NAME "libGL.so.1"
 #endif
