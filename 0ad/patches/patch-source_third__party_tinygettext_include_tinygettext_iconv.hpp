$NetBSD$

tinygettext fails with NetBSD iconv.
Use iconv from SDL2 instead.

--- source/third_party/tinygettext/include/tinygettext/iconv.hpp.orig	2021-07-27 21:57:05.000000000 +0000
+++ source/third_party/tinygettext/include/tinygettext/iconv.hpp
@@ -22,8 +22,11 @@
 
 #include <string>
 
+// pkgsrc
+#define TINYGETTEXT_WITH_SDL
+
 #ifdef TINYGETTEXT_WITH_SDL
-#  include "SDL.h"
+#  include "SDL2/SDL.h"
 #else
 #  include <iconv.h>
 #endif
