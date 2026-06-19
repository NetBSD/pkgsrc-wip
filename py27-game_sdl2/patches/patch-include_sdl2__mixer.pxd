$NetBSD$

--- include/sdl2_mixer.pxd.orig	2026-06-19 00:56:28.897423574 +0000
+++ include/sdl2_mixer.pxd
@@ -18,10 +18,8 @@ cdef extern from "SDL_mixer.h" nogil:
     ctypedef enum MIX_InitFlags:
         MIX_INIT_FLAC
         MIX_INIT_MOD
-        MIX_INIT_MODPLUG
         MIX_INIT_MP3
         MIX_INIT_OGG
-        MIX_INIT_FLUIDSYNTH
 
     int Mix_Init(int flags)
     void Mix_Quit()
