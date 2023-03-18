$NetBSD$

use system library

--- cmake/importCairo.cmake.orig	2022-12-25 04:16:41.697240255 +0000
+++ cmake/importCairo.cmake
@@ -22,6 +22,8 @@ if (BUILD_BUNDLE)
       add_third_party_dependency("cairo-1.17.4")
       add_third_party_dependency("libpng-1.6.37")
     endif()
+  elseif(NETBSD)
+    # use system library
   else() #Linux
     If(${CMAKE_SYSTEM_PROCESSOR} MATCHES "armv7l" OR (${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64"))
       add_third_party_dependency("pixman-0.40.0")
