$NetBSD$

From NetBSD xsrc 1.20.5

--- glx/glxscreens.h.orig	2019-05-30 18:27:34.000000000 +0000
+++ glx/glxscreens.h
@@ -116,7 +116,14 @@ GLint glxConvertToXVisualType(int visual
 ** and DDX layers of the GLX server extension.  The methods provide an
 ** interface for context management on a screen.
 */
+#if defined(__NetBSD__)
+#ifndef __GLXscreen
+#define __GLXscreen __GLXscreen
 typedef struct __GLXscreen __GLXscreen;
+#endif
+#else
+typedef struct __GLXscreen __GLXscreen;
+#endif
 struct __GLXscreen {
     void (*destroy) (__GLXscreen * screen);
 
