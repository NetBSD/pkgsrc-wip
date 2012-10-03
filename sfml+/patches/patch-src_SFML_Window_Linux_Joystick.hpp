$NetBSD: patch-src_SFML_Window_Linux_Joystick.hpp,v 1.1 2012/10/03 15:06:00 othyro Exp $

Adds NetBSD support.

--- src/SFML/Window/Linux/Joystick.hpp.orig	2010-03-18 13:15:05.000000000 +0000
+++ src/SFML/Window/Linux/Joystick.hpp
@@ -34,6 +34,9 @@
 #elif defined(SFML_SYSTEM_FREEBSD)
     // #include <sys/joystick.h> ?
     #define ABS_MAX 1
+#elif defined(SFML_SYSTEM_NETBSD)
+    #include <sys/joystick.h>
+    #define ABS_MAX 1
 #endif
 
 
