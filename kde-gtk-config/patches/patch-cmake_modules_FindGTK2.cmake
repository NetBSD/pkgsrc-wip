$NetBSD$

Add buildlink dirs to search path

--- cmake/modules/FindGTK2.cmake.orig	2016-04-19 11:06:46.000000000 +0000
+++ cmake/modules/FindGTK2.cmake
@@ -185,6 +185,8 @@ function(_GTK2_FIND_INCLUDE_DIR _var _hd
 
     find_path(${_var} ${_hdr}
         PATHS
+	    ${BUILDLINK_DIR}/include/glib
+	    ${BUILDLINK_DIR}/lib
             /usr/local/lib64
             /usr/local/lib
             /usr/lib64
