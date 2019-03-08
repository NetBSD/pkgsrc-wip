--- src/unix/video.c	2018-12-28 14:34:51.000000000 +0100
+++ src/unix/video.c	2019-03-08 13:50:50.311966435 +0100
@@ -33,7 +33,7 @@
 #include "refresh/refresh.h"
 #include "system/system.h"
 #include "res/q2pro.xbm"
-#include <SDL.h>
+#include <SDL2/SDL.h>
 
 static SDL_Window       *sdl_window;
 static SDL_GLContext    *sdl_context;
