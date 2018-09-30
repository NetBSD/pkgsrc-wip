$NetBSD$

Match SDL1 include paths

--- src/love.cpp.orig	2011-05-04 16:00:10.000000000 +0000
+++ src/love.cpp
@@ -38,7 +38,7 @@
 #ifdef LOVE_BUILD_EXE
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 // Modules
 #include <audio/wrap_Audio.h>
