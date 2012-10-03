$NetBSD: patch-src_SFML_Window_Linux_Joystick.cpp,v 1.1 2012/10/03 15:06:00 othyro Exp $

Adds NetBSD support.

--- src/SFML/Window/Linux/Joystick.cpp.orig	2010-01-27 14:00:27.000000000 +0000
+++ src/SFML/Window/Linux/Joystick.cpp
@@ -175,7 +175,7 @@ unsigned int Joystick::GetButtonsCount()
 }
 
 
-#elif defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
 
 ////////////////////////////////////////////////////////////
@@ -212,7 +212,7 @@ unsigned int Joystick::GetButtonsCount()
     return 0;
 }
 
-#endif // defined(SFML_SYSTEM_FREEBSD)
+#endif // defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
 } // namespace priv
 
