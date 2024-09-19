--- src/refresh/qgl.h	2018-12-28 14:34:51.000000000 +0100
+++ src/refresh/qgl.h	2019-03-08 13:48:06.995958009 +0100
@@ -20,7 +20,7 @@
 #define QGL_H
 
 #if USE_SDL
-#include <SDL_opengl.h>
+#include <SDL2/SDL_opengl.h>
 #else
 #include <GL/gl.h>
 #include <GL/glext.h>
