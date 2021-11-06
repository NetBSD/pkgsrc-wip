$NetBSD$

Add ${PREFIX} path

--- cmake_modules/FindNLopt.cmake.orig	2021-01-12 14:09:17.158086606 +0000
+++ cmake_modules/FindNLopt.cmake
@@ -29,6 +29,8 @@ FIND_PATH(NLopt_INCLUDE_DIRS nlopt.hpp
     /opt/local/include/nlopt/
     /usr/local/include/
     /usr/local/include/nlopt/
+    @prefix@/include/
+    @prefix@/include/nlopt/
     /usr/include
     /usr/include/nlopt/)
 
@@ -44,6 +46,8 @@ set(LIB_SEARCHDIRS 
     /opt/local/lib/nlopt/
     /usr/local/lib/
     /usr/local/lib/nlopt/
+    @prefix@/lib/
+    @prefix@/lib/nlopt/
     /usr/lib/nlopt
 )
 
