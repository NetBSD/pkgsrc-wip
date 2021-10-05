$NetBSD$

* The gumbo package does not install cmake packages so this line breaks
  find_package(litehtml) . This line is not needed when litehtml is used
  as a shared library.

--- cmake/litehtmlConfig.cmake.orig	2021-09-03 06:59:31.000000000 +0000
+++ cmake/litehtmlConfig.cmake
@@ -1,3 +1,3 @@
 include(CMakeFindDependencyMacro)
-find_dependency(gumbo)
+#find_dependency(gumbo)
 include(${CMAKE_CURRENT_LIST_DIR}/litehtmlTargets.cmake)
