$NetBSD$

ECM_MODULE_DIR wants a single directory, not a path

--- Source/cmake/OptionsQt.cmake.orig	2017-06-15 23:36:48.000000000 +0000
+++ Source/cmake/OptionsQt.cmake
@@ -1,7 +1,7 @@
 include(FeatureSummary)
 include(ECMPackageConfigHelpers)
 
-set(ECM_MODULE_DIR ${CMAKE_MODULE_PATH})
+set(ECM_MODULE_DIR "${CMAKE_SOURCE_DIR}/Source/cmake")
 
 set(PROJECT_VERSION_MAJOR 5)
 set(PROJECT_VERSION_MINOR 212)
