# $NetBSD$

Don't assume that we've enabled OpenGL support.

--- ./src/video/graphic.cpp.orig	2019-07-06 12:48:14.597944334 -0700
+++ ./src/video/graphic.cpp	2019-07-06 13:01:30.326334963 -0700
@@ -1648,7 +1648,8 @@
 	}
 }
 
-bool CGraphic::DeleteColorCyclingTextures() {
+#if defined(USE_OPENGL) || defined(USE_GLES)
+bool DeleteColorCyclingTextures() {
 	if (!ColorCyclingTextures) return false;
 	for (int i = 0; i < NumColorCycles; i++) {
 		glDeleteTextures(NumTextures, ColorCyclingTextures[i]);
@@ -1658,5 +1659,6 @@
 	ColorCyclingTextures = NULL;
 	return true;
 }
+#endif
 
 //@}
