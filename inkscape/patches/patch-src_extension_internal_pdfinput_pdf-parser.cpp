$NetBSD$

# Hack for case-insensitive filesystems
# Is this an upstream issue, or caused by pkgsrc?

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2023-11-08 22:45:44.418046780 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -37,7 +37,9 @@
 #include "GfxState.h"
 #include "GlobalParams.h"
 #include "Lexer.h"
-#include "Object.h"
+// Make sure we get poppler/Object.h and not python/object.h on
+// case-insensitive filesystems (macOS)
+#include "poppler/Object.h"
 #include "OutputDev.h"
 #include "PDFDoc.h"
 #include "Page.h"
