$NetBSD$

Match include path for SDL<2

--- src/modules/joystick/sdl/Joystick.h.orig	2012-04-06 18:15:02.000000000 +0000
+++ src/modules/joystick/sdl/Joystick.h
@@ -26,7 +26,7 @@
 #include <common/EnumMap.h>
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 namespace love
 {
