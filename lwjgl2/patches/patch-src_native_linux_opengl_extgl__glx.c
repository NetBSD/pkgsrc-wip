$NetBSD$

Detect `__NetBSD__` macro.  `dlopen` OpenGL as "libGL.so".

--- src/native/linux/opengl/extgl_glx.c.orig	2026-11-11 02:54:19.896995865 +0000
+++ src/native/linux/opengl/extgl_glx.c
@@ -220,7 +220,7 @@ bool extgl_Open(JNIEnv *env) {
 	 *
 	 * DRI drivers need this flag to work properly
 	 */
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 	lib_gl_handle = dlopen("libGL.so", RTLD_LAZY | RTLD_GLOBAL);
 #else
 	lib_gl_handle = dlopen("libGL.so.1", RTLD_LAZY | RTLD_GLOBAL);
