$NetBSD$

Use GLEW for GL extensions, works around a linking problem on NetBSD.

--- Source_Files/RenderMain/OGL_Headers.h.orig	2021-06-26 01:15:50.000000000 +0000
+++ Source_Files/RenderMain/OGL_Headers.h
@@ -30,11 +30,8 @@
 
 #else
 
-#ifndef GL_GLEXT_PROTOTYPES
-#define GL_GLEXT_PROTOTYPES 1
-#endif
 
-#include <SDL2/SDL_opengl.h>
+#include <GL/glew.h>
 
 #if defined (__APPLE__) && defined(__MACH__)
 #include <OpenGL/glu.h>
