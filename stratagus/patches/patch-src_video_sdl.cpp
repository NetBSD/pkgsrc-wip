# $NetBSD$

Don't assume that we've enabled OpenGL support.

--- ./src/video/sdl.cpp.orig	2019-07-06 13:08:50.493609592 -0700
+++ ./src/video/sdl.cpp	2019-07-06 13:09:05.285127661 -0700
@@ -639,12 +639,14 @@
 	if (TheScreen == NULL) {
 		fprintf(stderr, "Couldn't set %dx%dx%d video mode: %s\n",
 				Video.Width, Video.Height, Video.Depth, SDL_GetError());
+#if defined(USE_OPENGL) || defined(USE_GLES)
 		if (UseOpenGL) {
 			fprintf(stderr, "Re-trying video without OpenGL\n");
 			UseOpenGL = false;
 			InitVideoSdl();
 			return;
 		}
+#endif
 		if (Video.FullScreen) {
 			fprintf(stderr, "Re-trying video without fullscreen mode\n");
 			Video.FullScreen = false;
