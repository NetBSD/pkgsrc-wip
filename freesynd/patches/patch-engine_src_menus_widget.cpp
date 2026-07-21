$NetBSD$

Use utf8cpp from pkgsrc

--- engine/src/menus/widget.cpp.orig	2026-07-20 06:12:13.848975755 +0000
+++ engine/src/menus/widget.cpp
@@ -23,7 +23,7 @@
 
 #include <stdarg.h>
 
-#include "utf8.h"
+#include <utf8cpp/utf8.h>
 
 #include "fs-utils/log/log.h"
 #include "fs-engine/menus/menu.h"
