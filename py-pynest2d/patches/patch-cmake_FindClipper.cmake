$NetBSD$

Add ${PREFIX} path

--- cmake/FindClipper.cmake.orig	2021-01-12 15:41:07.008690358 +0000
+++ cmake/FindClipper.cmake
@@ -32,6 +32,8 @@ find_path(CLIPPER_INCLUDE_DIRS clipper.h
     /opt/local/include/polyclipping/
     /usr/local/include/
     /usr/local/include/polyclipping/
+    @prefix@/include/
+    @prefix@/include/polyclipping/
     /usr/include
     /usr/include/polyclipping/
 )
@@ -50,6 +52,8 @@ set(LIB_SEARCHDIRS 
     /opt/local/lib/polyclipping/
     /usr/local/lib/
     /usr/local/lib/polyclipping/
+    @prefix@/lib/
+    @prefix@/lib/polyclipping/
     /usr/lib/polyclipping
 )
 
