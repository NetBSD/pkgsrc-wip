$NetBSD$

Match SDL1 include paths

--- src/modules/thread/sdl/Thread.h.orig	2011-05-04 16:00:10.000000000 +0000
+++ src/modules/thread/sdl/Thread.h
@@ -22,8 +22,8 @@
 #define LOVE_THREAD_SDL_THREAD_H
 
 // SDL
-#include <SDL_thread.h>
-#include <SDL_mutex.h>
+#include <SDL/SDL_thread.h>
+#include <SDL/SDL_mutex.h>
 
 // STL
 #include <map>
