$NetBSD$

Add missing include.
https://github.com/mlua-rs/luau-src-rs/issues/11

--- ../vendor/luau0-src-0.22.0+luau740/luau/CodeGen/src/IrUtils.cpp.orig	2026-11-21 14:36:01.090211265 +0000
+++ ../vendor/luau0-src-0.22.0+luau740/luau/CodeGen/src/IrUtils.cpp
@@ -13,6 +13,7 @@
 #include "lnumutils.h"
 
 #include <algorithm>
+#include <limits>
 #include <vector>
 
 #include <limits.h>
