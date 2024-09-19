--- src/unix/system.c	2018-12-28 14:34:51.000000000 +0100
+++ src/unix/system.c	2019-03-08 13:51:42.469969126 +0100
@@ -44,7 +44,7 @@
 #endif
 
 #if USE_SDL
-#include <SDL.h>
+#include <SDL2/SDL.h>
 #endif
 
 cvar_t  *sys_basedir;
