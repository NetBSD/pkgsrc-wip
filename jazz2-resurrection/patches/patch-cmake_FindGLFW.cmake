$NetBSD$

Also search PKGSRC include directories.

--- cmake/FindGLFW.cmake.orig	2023-12-27 21:41:38.655108151 +0000
+++ cmake/FindGLFW.cmake
@@ -32,6 +32,7 @@ find_path(GLFW_INCLUDE_DIR NAMES glfw3.h
   /include/GLFW/
   /usr/include/GLFW
   /usr/local/include/GLFW
+  ${PKGSRC_INCLUDE}/GLFW/
   ${GLFW_ROOT_DIR}/include/ # added by ptr
   ${EXTERNAL_INCLUDES_DIR}/GL/
 )
