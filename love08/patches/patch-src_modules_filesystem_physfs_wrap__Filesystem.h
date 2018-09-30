$NetBSD$

Match include path for SDL<2

--- src/modules/filesystem/physfs/wrap_Filesystem.h.orig	2012-04-06 18:15:01.000000000 +0000
+++ src/modules/filesystem/physfs/wrap_Filesystem.h
@@ -27,7 +27,7 @@
 #include "wrap_FileData.h"
 
 // SDL
-#include <SDL_loadso.h>
+#include <SDL/SDL_loadso.h>
 
 namespace love
 {
