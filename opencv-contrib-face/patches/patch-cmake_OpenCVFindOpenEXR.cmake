$NetBSD: patch-cmake_OpenCVFindOpenEXR.cmake,v 1.1 2021/07/08 21:27:39 markd Exp $

openexr3

--- cmake/OpenCVFindOpenEXR.cmake.orig	2022-12-28 14:31:52.000000000 +0000
+++ cmake/OpenCVFindOpenEXR.cmake
@@ -25,6 +25,14 @@ if(NOT OPENCV_SKIP_OPENEXR_FIND_PACKAGE)
   endif()
 endif()
 
+find_package(OpenEXR 3.0 CONFIG QUIET)
+if(TARGET OpenEXR::OpenEXR)
+    SET(OPENEXR_FOUND TRUE)
+    SET(OPENEXR_LIBRARIES OpenEXR::OpenEXR)
+    SET(OPENEXR_VERSION ${OpenEXR_VERSION})
+    return()
+endif()
+
 SET(OPENEXR_LIBRARIES "")
 SET(OPENEXR_LIBSEARCH_SUFFIXES "")
 file(TO_CMAKE_PATH "$ENV{ProgramFiles}" ProgramFiles_ENV_PATH)
