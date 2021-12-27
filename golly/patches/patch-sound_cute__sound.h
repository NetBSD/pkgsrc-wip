$NetBSD$

--- sound/cute_sound.h.orig	2021-10-29 21:32:39.000000000 +0000
+++ sound/cute_sound.h
@@ -618,15 +618,11 @@ cs_plugin_id_t cs_add_plugin(cs_context_
 	#define timespec // Avoids duplicate definitions.
 	#undef timespec // You must compile with POSIX features enabled.
 	#include <pthread.h>
-	#include <alloca.h>
 	#include <assert.h>
 
 #elif CUTE_SOUND_PLATFORM == CUTE_SOUND_SDL
 
 	#include <SDL2/SDL.h>
-	#ifndef _WIN32
-		#include <alloca.h>
-	#endif
 
 #else
 
