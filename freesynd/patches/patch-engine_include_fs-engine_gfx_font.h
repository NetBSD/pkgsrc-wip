$NetBSD$

Use utf8cpp from pkgsrc

--- engine/include/fs-engine/gfx/font.h.orig	2026-07-20 06:08:32.492440218 +0000
+++ engine/include/fs-engine/gfx/font.h
@@ -26,7 +26,7 @@
 #define FONT_H
 
 #include <map>
-#include "utf8.h"
+#include <utf8cpp/utf8.h>
 
 #include "fs-utils/common.h"
 #include "spritemanager.h"
