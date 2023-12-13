$NetBSD$

Fix deprecation warning

--- src/TextBuffer.h.orig	2023-12-13 10:11:02.328339019 +0000
+++ src/TextBuffer.h
@@ -8,7 +8,7 @@
 #include "Util/string_view.h"
 #include "gap_buffer.h"
 
-#include <gsl/gsl_util>
+#include <gsl/util>
 
 #include <cstdint>
 #include <deque>
