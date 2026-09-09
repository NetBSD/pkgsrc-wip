$NetBSD$

Use <cmath> for std::round()

--- libraries/ZWidget/src/window/sdl2/sdl2_display_window.cpp.orig	2026-08-30 21:11:51.243872748 +0000
+++ libraries/ZWidget/src/window/sdl2/sdl2_display_window.cpp
@@ -3,6 +3,7 @@
 #include <SDL2/SDL_video.h>
 #include <stdexcept>
 #include <atomic>
+#include <cmath>
 #include <mutex>
 #include <SDL2/SDL_vulkan.h>
 #include <SDL2/SDL_hints.h>
