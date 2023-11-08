$NetBSD$

# Hack for case-insensitive filesystems
# Is this an upstream issue, or caused by pkgsrc?

--- src/extension/internal/pdfinput/pdf-parser.h.orig	2023-11-08 22:47:37.318379172 +0000
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -37,7 +37,9 @@ namespace Inkscape {
 using Inkscape::Extension::Internal::SvgBuilder;
 
 #include "glib/poppler-features.h"
-#include "Object.h"
+// Make sure we get poppler/Object.h and not python/object.h on
+// case-insensitive filesystems (macOS)
+#include "poppler/Object.h"
 
 #include <map>
 #include <memory>
