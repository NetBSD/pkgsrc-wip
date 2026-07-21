$NetBSD$

Use utf8cpp from pkgsrc

--- engine/src/system/sdl/system_sdl.cpp.orig	2026-07-20 06:05:53.098751914 +0000
+++ engine/src/system/sdl/system_sdl.cpp
@@ -32,7 +32,7 @@
 #include <SDL_image.h>
 #include <algorithm>
 #include <format>
-#include "utf8.h"
+#include <utf8cpp/utf8.h>
 
 #include "fs-engine/config.h"
 #include "fs-engine/sound/audio.h"
