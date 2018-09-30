$NetBSD$

Match SDL1 include paths

--- src/modules/audio/openal/Audio.h.orig	2011-05-04 16:00:10.000000000 +0000
+++ src/modules/audio/openal/Audio.h
@@ -28,7 +28,7 @@
 #include <cmath>
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 // LOVE
 #include <audio/Audio.h>
