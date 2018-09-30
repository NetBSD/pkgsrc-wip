$NetBSD$

Match SDL1 include paths

--- src/modules/keyboard/sdl/wrap_Keyboard.h.orig	2011-05-04 16:00:10.000000000 +0000
+++ src/modules/keyboard/sdl/wrap_Keyboard.h
@@ -26,7 +26,7 @@
 #include "Keyboard.h"
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 namespace love
 {
