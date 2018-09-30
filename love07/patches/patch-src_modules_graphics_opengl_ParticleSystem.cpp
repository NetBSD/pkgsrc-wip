$NetBSD$

Match SDL1 include paths

--- src/modules/graphics/opengl/ParticleSystem.cpp.orig	2011-05-04 16:00:10.000000000 +0000
+++ src/modules/graphics/opengl/ParticleSystem.cpp
@@ -22,7 +22,7 @@
 
 #include <common/math.h>
 
-#include <SDL_opengl.h>
+#include <SDL/SDL_opengl.h>
 #include <cmath>
 #include <cstdlib>
 #include <cstring>
