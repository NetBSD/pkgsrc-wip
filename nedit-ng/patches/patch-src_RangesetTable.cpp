$NetBSD$

Fix deprecation warning

--- src/RangesetTable.cpp.orig	2023-12-13 10:09:15.392317895 +0000
+++ src/RangesetTable.cpp
@@ -2,7 +2,7 @@
 #include "RangesetTable.h"
 #include "TextBuffer.h"
 #include <array>
-#include <gsl/gsl_util>
+#include <gsl/util>
 #include <string>
 
 namespace {
