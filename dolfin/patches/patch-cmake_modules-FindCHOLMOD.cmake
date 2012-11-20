$NetBSD: patch-cmake_modules-FindCHOLMOD.cmake,v 1.1 2012/11/20 17:00:57 outpaddling Exp $

--- cmake/modules/FindCHOLMOD.cmake.orig	2011-12-07 21:21:22.000000000 +0000
+++ cmake/modules/FindCHOLMOD.cmake
@@ -66,6 +66,7 @@ endif()
 if (LAPACK_FOUND)
   set(CHOLMOD_LIBRARIES ${CHOLMOD_LIBRARIES} ${LAPACK_LIBRARIES})
 endif()
+set(CHOLMOD_LIBRARIES ${CHOLMOD_LIBRARIES} $ENV{LOCALBASE}/lib/libsuitesparseconfig.a)
 
 mark_as_advanced(
   CHOLMOD_INCLUDE_DIRS
