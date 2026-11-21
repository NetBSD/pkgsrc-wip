$NetBSD$

Add missing header.
https://github.com/mlua-rs/luau-src-rs/issues/11

--- ../vendor/luau0-src-0.22.0+luau740/luau/Compiler/src/Compiler.cpp.orig	2026-11-21 14:38:25.372767206 +0000
+++ ../vendor/luau0-src-0.22.0+luau740/luau/Compiler/src/Compiler.cpp
@@ -20,6 +20,7 @@
 #include <algorithm>
 #include <array>
 #include <bitset>
+#include <limits>
 
 #include <math.h>
 #include <stdlib.h>
