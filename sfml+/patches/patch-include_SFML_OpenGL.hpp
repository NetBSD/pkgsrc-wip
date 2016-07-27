$NetBSD$

--- include/SFML/OpenGL.hpp.orig	2015-08-24 16:01:06.000000000 +0000
+++ include/SFML/OpenGL.hpp
@@ -45,7 +45,7 @@
 
     #include <GL/gl.h>
 
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
     #if defined(SFML_OPENGL_ES)
         #include <GLES/gl.h>
