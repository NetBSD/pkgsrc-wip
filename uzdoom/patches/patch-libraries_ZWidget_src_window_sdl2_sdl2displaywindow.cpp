$NetBSD$

Use <cmath> for std::round()

--- libraries/ZWidget/src/window/sdl2/sdl2displaywindow.cpp.orig	2026-07-17 18:49:06.642652976 +0000
+++ libraries/ZWidget/src/window/sdl2/sdl2displaywindow.cpp
@@ -1,5 +1,6 @@
 
 #include "sdl2displaywindow.h"
+#include <cmath>
 #include <stdexcept>
 
 Uint32 SDL2DisplayWindow::PaintEventNumber = 0xffffffff;
