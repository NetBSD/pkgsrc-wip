$NetBSD$

use system library

--- cmake/importCairo.cmake.orig	2026-07-15 12:37:44.000000000 +0000
+++ cmake/importCairo.cmake
@@ -16,6 +16,8 @@ if (BUILD_BUNDLE)
     add_third_party_dependency("pixman-0.44.2")
     add_third_party_dependency("cairo-1.18.4")
     add_third_party_dependency("libpng-1.6.47")
+  elseif(NETBSD)
+    # use system library
   else() #Linux
     If(${CMAKE_SYSTEM_PROCESSOR} MATCHES "armv7l" OR (${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64"))
       add_third_party_dependency("pixman-0.40.0")
