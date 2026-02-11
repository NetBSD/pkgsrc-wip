$NetBSD$

--- cmake/cxx.cmake.orig	2026-02-11 21:34:18.675740526 +0000
+++ cmake/cxx.cmake
@@ -47,6 +47,10 @@ endif()
   # Ensures that libraries from dependencies in LOCALBASE are used
   list(APPEND cxx_linker_base -L/usr/local/lib)
 endif()
+if (CMAKE_SYSTEM_NAME STREQUAL "NetBSD")
+  # libinotify uses c99 extension, so suppress this error
+  list(APPEND cxx_base -Wno-c99-extensions)
+endif()
 
 # Check compiler
 if(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
