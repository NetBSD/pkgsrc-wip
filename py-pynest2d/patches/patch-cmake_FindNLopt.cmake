$NetBSD$

Add ${PREFIX} path

--- cmake/FindNLopt.cmake.orig	2021-01-12 15:41:30.390958582 +0000
+++ cmake/FindNLopt.cmake
@@ -29,6 +29,8 @@ find_path(NLopt_INCLUDE_DIRS nlopt.hpp
     /opt/local/include/nlopt/
     /usr/local/include/
     /usr/local/include/nlopt/
+    @prefix@/include/
+    @prefix@/include/nlopt/
     /usr/include
     /usr/include/nlopt/
 )
@@ -45,6 +47,8 @@ set(LIB_SEARCHDIRS 
     /opt/local/lib/nlopt/
     /usr/local/lib/
     /usr/local/lib/nlopt/
+    @prefix@/lib/
+    @prefix@/lib/nlopt/
     /usr/lib/nlopt
 )
 
