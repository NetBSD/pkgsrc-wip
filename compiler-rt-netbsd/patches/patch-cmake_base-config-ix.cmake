$NetBSD$

--- cmake/base-config-ix.cmake.orig	2017-07-04 05:53:17.000000000 +0000
+++ cmake/base-config-ix.cmake
@@ -4,6 +4,8 @@
 # runtime libraries.
 
 include(CheckIncludeFile)
+include(CheckCXXSourceCompiles)
+
 check_include_file(unwind.h HAVE_UNWIND_H)
 
 # Top level target used to build all compiler-rt libraries.
@@ -86,6 +88,17 @@ if(APPLE)
   option(COMPILER_RT_ENABLE_IOS "Enable building for iOS" On)
   option(COMPILER_RT_ENABLE_WATCHOS "Enable building for watchOS - Experimental" Off)
   option(COMPILER_RT_ENABLE_TVOS "Enable building for tvOS - Experimental" Off)
+
+  CHECK_CXX_SOURCE_COMPILES("
+      static thread_local int blah;
+      int main() {
+        return 0;
+      }
+      " HAS_THREAD_LOCAL)
+
+  if( NOT HAS_THREAD_LOCAL )
+    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Dthread_local=__thread")
+  endif()
 else()
   option(COMPILER_RT_DEFAULT_TARGET_ONLY "Build builtins only for the default target" Off)
 endif()
