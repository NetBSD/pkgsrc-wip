$NetBSD$

Also support other BSDs.

--- codemp/rd-rend2/qgl.h.orig	2024-08-23 18:45:06.206284407 +0000
+++ codemp/rd-rend2/qgl.h
@@ -14,7 +14,7 @@
 #	if defined(__FX__)
 #		include <GL/fxmesa.h>
 #	endif
-#elif defined( __FreeBSD__ ) // rb010123
+#elif defined( __FreeBSD__ ) || defined( __NetBSD__ ) || defined( __OpenBSD__ )// rb010123
 #	include <GL/gl.h>
 #	include <GL/glx.h>
 #	if defined(__FX__)
