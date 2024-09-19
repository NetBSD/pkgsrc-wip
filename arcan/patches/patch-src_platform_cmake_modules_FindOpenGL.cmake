$NetBSD$

Tolerate /usr/X11R7/lib, too.
XXX possibly not necessary

--- src/platform/cmake/modules/FindOpenGL.cmake.orig	2018-12-10 23:33:36.000000000 +0000
+++ src/platform/cmake/modules/FindOpenGL.cmake
@@ -84,7 +84,7 @@ else ()
 			NAMES GL MesaGL OSMesa
       PATHS /opt/graphics/OpenGL/lib
             /usr/openwin/lib
-            /usr/shlib /usr/X11R6/lib
+	    /usr/shlib /usr/X11R6/lib /usr/X11R7/lib
             ${_OPENGL_LIB_PATH}
     )
 
