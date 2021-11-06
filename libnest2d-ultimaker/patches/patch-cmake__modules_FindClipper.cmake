$NetBSD$

Add ${PREFIX} path

--- cmake_modules/FindClipper.cmake.orig	2021-01-12 14:05:41.769561283 +0000
+++ cmake_modules/FindClipper.cmake
@@ -32,6 +32,8 @@ FIND_PATH(CLIPPER_INCLUDE_DIRS clipper.h
     /opt/local/include/polyclipping/
     /usr/local/include/
     /usr/local/include/polyclipping/
+    @prefix@/include/
+    @prefix@/include/polyclipping/
     /usr/include
     /usr/include/polyclipping/)
 
@@ -49,6 +51,8 @@ set(LIB_SEARCHDIRS 
     /opt/local/lib/polyclipping/
     /usr/local/lib/
     /usr/local/lib/polyclipping/
+    @prefix@/lib/
+    @prefix@/lib/polyclipping/
     /usr/lib/polyclipping
 )
 
