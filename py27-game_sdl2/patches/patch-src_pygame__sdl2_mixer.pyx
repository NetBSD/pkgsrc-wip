$NetBSD$

--- src/pygame_sdl2/mixer.pyx.orig	2026-06-19 00:56:45.361380927 +0000
+++ src/pygame_sdl2/mixer.pyx
@@ -81,8 +81,8 @@ def init(frequency=22050, size=MIX_DEFAULT_FORMAT, cha
     if get_init() is not None:
         return
 
-    for flag in (MIX_INIT_FLAC, MIX_INIT_MOD, MIX_INIT_MODPLUG,
-                 MIX_INIT_MP3, MIX_INIT_OGG, MIX_INIT_FLUIDSYNTH):
+    for flag in (MIX_INIT_FLAC, MIX_INIT_MOD,
+                 MIX_INIT_MP3, MIX_INIT_OGG):
 
         if Mix_Init(flag) != flag:
             errors.append("{}\n".format(SDL_GetError()))
