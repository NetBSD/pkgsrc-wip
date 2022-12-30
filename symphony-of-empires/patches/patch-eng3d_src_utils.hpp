$NetBSD$

Need an extra #include (for memcpy())

--- eng3d/src/utils.hpp.orig	2022-12-29 17:34:59.695718593 -0800
+++ eng3d/src/utils.hpp	2022-12-29 17:37:37.219948875 -0800
@@ -25,6 +25,7 @@
 #pragma once
 
 #include <cstdint>
+#include <cstring>
 
 #if !defined(__cpp_lib_byteswap) || __cpp_lib_byteswap < 202110L
 #   include <bit>
