$NetBSD$

add NetBSD support

--- include/SFML/OpenGL.hpp.orig	2018-10-15 19:41:39.000000000 +0000
+++ include/SFML/OpenGL.hpp
@@ -45,7 +45,7 @@
 
     #include <GL/gl.h>
 
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_OPENBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD) || defined(SFML_SYSTEM_OPENBSD)
 
     #if defined(SFML_OPENGL_ES)
         #include <GLES/gl.h>
