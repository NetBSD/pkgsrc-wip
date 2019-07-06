# $NetBSD$

Don't assume that we've enabled OpenGL support.

--- ./src/video/video.cpp.orig	2019-07-06 13:04:36.686202361 -0700
+++ ./src/video/video.cpp	2019-07-06 13:04:46.356626653 -0700
@@ -394,11 +394,13 @@
 
 void SetColorCycleAll(bool value)
 {
+#if defined(USE_OPENGL) || defined(USE_GLES)
 	if (UseOpenGL) {
 		// FIXME: In OpenGL-mode, we can only cycle the tileset graphic
 		return;
 	}
 	CColorCycling::GetInstance().ColorCycleAll = value;
+#endif
 }
 
 /**
