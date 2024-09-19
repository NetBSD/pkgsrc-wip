$NetBSD$

Patch from NetBSD xsrc:

Jan 22 20:25:45 2019

protect dup typedef.

--- include/glx_extinit.h.orig	2019-05-30 18:27:34.000000000 +0000
+++ include/glx_extinit.h
@@ -30,7 +30,14 @@
 /* XXX this comment no longer makes sense i think */
 #ifdef GLXEXT
 typedef struct __GLXprovider __GLXprovider;
+#if defined(__NetBSD__)
+#ifndef __GLXscreen
+#define __GLXscreen __GLXscreen
 typedef struct __GLXscreen __GLXscreen;
+#endif
+#else
+typedef struct __GLXscreen __GLXscreen;
+#endif
 struct __GLXprovider {
     __GLXscreen *(*screenProbe) (ScreenPtr pScreen);
     const char *name;
