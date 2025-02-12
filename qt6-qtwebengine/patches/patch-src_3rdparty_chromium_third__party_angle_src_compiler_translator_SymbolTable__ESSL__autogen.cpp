$NetBSD$

otherwise isnan and isinf are macros on NetBSD that are applied and
mess this up

--- src/3rdparty/chromium/third_party/angle/src/compiler/translator/SymbolTable_ESSL_autogen.cpp.orig	2025-01-19 05:40:08.771794310 +0000
+++ src/3rdparty/chromium/third_party/angle/src/compiler/translator/SymbolTable_ESSL_autogen.cpp
@@ -9,6 +9,7 @@
 // SymbolTable_ESSL_autogen.cpp:
 //   Compile-time initialized built-ins.
 
+#include <cmath>
 #include "compiler/translator/SymbolTable.h"
 
 #include "angle_gl.h"
