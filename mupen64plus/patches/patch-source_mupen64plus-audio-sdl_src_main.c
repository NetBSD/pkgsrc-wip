$NetBSD: patch-source_mupen64plus-audio-sdl_src_main.c,v 1.2 2013/07/06 23:00:14 othyro Exp $

Fix SDL include paths. Not sure if this is a kludge.

--- source/mupen64plus-audio-sdl/src/main.c.orig	2013-07-04 00:28:02.000000000 +0000
+++ source/mupen64plus-audio-sdl/src/main.c
@@ -26,8 +26,8 @@
 #include <stdlib.h>
 #include <string.h>
 
-#include <SDL.h>
-#include <SDL_audio.h>
+#include <SDL/SDL.h>
+#include <SDL/SDL_audio.h>
 
 #ifdef USE_SRC
 #include <samplerate.h>
