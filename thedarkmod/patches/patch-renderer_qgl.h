$NetBSD$

Use GL/gl.h on !linux...

--- renderer/qgl.h.orig	2019-02-02 17:51:32.000000000 +0000
+++ renderer/qgl.h
@@ -29,19 +29,13 @@
 #define GL_GLEXT_LEGACY
 #include <OpenGL/gl.h>
 
-#elif defined( __linux__ )
-
+#else
 // using our local glext.h
 // http://oss.sgi.com/projects/ogl-sample/ABI/
 #define GL_GLEXT_LEGACY
 #define GLX_GLXEXT_LEGACY
 #include <GL/gl.h>
 #include <GL/glx.h>
-
-#else
-
-#include <gl.h>
-
 #endif
 
 #ifndef APIENTRY
@@ -507,8 +501,6 @@ extern BOOL ( WINAPI * qwglSwapLayerBuff
 
 #endif	// _WIN32
 
-#if defined( __linux__ )
-
 //GLX Functions
 extern XVisualInfo * (*qglXChooseVisual)( Display *dpy, int screen, int *attribList );
 extern GLXContext (*qglXCreateContext)( Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct );
@@ -523,8 +515,6 @@ extern GLExtension_t (*qglXGetProcAddres
 	#include "../sys/linux/qgl_enforce.h"
 #endif
 
-#endif // __linux__
-
 #endif	// hardlinlk vs dlopen
 
 #endif
