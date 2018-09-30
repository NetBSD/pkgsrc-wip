$NetBSD$

Match include paths for SDL<2

--- src/modules/thread/sdl/threads.h.orig	2012-03-05 17:47:40.000000000 +0000
+++ src/modules/thread/sdl/threads.h
@@ -21,7 +21,7 @@
 #ifndef LOVE_THREAD_SDL_THREADS_H
 #define LOVE_THREAD_SDL_THREADS_H
 
-#include "SDL.h"
+#include <SDL/SDL.h>
 #include <common/config.h>
 
 namespace love
