$NetBSD$

Fix the test for the fluidsynth version.

--- jfaudiolib/src/driver_fluidsynth.c.orig	2018-12-18 11:55:00.000000000 +0000
+++ jfaudiolib/src/driver_fluidsynth.c
@@ -36,8 +36,8 @@
 #include <glob.h>
 
 #if ((FLUIDSYNTH_VERSION_MAJOR < 1) || \
-     (FLUIDSYNTH_VERSION_MAJOR >= 1 && FLUIDSYNTH_VERSION_MINOR < 1) || \
-     (FLUIDSYNTH_VERSION_MAJOR >= 1 && FLUIDSYNTH_VERSION_MINOR >= 1 && FLUIDSYNTH_VERSION_MICRO < 2))
+     (FLUIDSYNTH_VERSION_MAJOR == 1 && FLUIDSYNTH_VERSION_MINOR < 1) || \
+     (FLUIDSYNTH_VERSION_MAJOR == 1 && FLUIDSYNTH_VERSION_MINOR == 1 && FLUIDSYNTH_VERSION_MICRO < 2))
 #error "FluidSynth support requires version 1.1.2 or better"
 #endif
 
