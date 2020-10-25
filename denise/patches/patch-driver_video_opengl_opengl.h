$NetBSD$

Lots of functions remain undeclared in the original. I'm not sure which
header should be included. With <GL/glew.h> you also need to link with -lGLEW
which makes me uncomfortable.

--- driver/video/opengl/opengl.h.orig	2020-10-25 12:34:43.000000000 +0000
+++ driver/video/opengl/opengl.h
@@ -6,6 +6,7 @@
     #include <GL/glext.h>
     #define glGetProcAddress(name) wglGetProcAddress(name)
 #else
+    #include <GL/glew.h>
     #include <GL/gl.h>
     #include <GL/glx.h>
     #define glGetProcAddress(name) (*glXGetProcAddress)((const GLubyte*)(name))
