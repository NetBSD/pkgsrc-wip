$NetBSD: patch-src_SFML_Window_Joystick.hpp,v 1.1 2012/10/03 15:06:00 othyro Exp $

Adds NetBSD support.

--- src/SFML/Window/Joystick.hpp.orig	2010-01-27 14:00:37.000000000 +0000
+++ src/SFML/Window/Joystick.hpp
@@ -66,7 +66,7 @@ struct JoystickState
 
     #include <SFML/Window/Win32/Joystick.hpp>
 
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
     #include <SFML/Window/Linux/Joystick.hpp>
 
