$NetBSD$

Match include path for SDL<2

--- src/modules/mouse/sdl/Mouse.cpp.orig	2012-04-06 18:15:02.000000000 +0000
+++ src/modules/mouse/sdl/Mouse.cpp
@@ -21,7 +21,7 @@
 #include "Mouse.h"
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 namespace love
 {
