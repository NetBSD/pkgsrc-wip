$NetBSD$

Match include path for SDL<2

--- src/modules/event/sdl/Event.h.orig	2012-04-06 18:15:01.000000000 +0000
+++ src/modules/event/sdl/Event.h
@@ -27,7 +27,7 @@
 #include <common/EnumMap.h>
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 namespace love
 {
