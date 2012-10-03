$NetBSD: patch-src_SFML_Window_WindowImpl.cpp,v 1.1 2012/10/03 15:06:00 othyro Exp $

Adds NetBSD support.

--- src/SFML/Window/WindowImpl.cpp.orig	2010-01-27 14:00:37.000000000 +0000
+++ src/SFML/Window/WindowImpl.cpp
@@ -36,7 +36,7 @@
     #include <SFML/Window/Win32/WindowImplWin32.hpp>
     typedef sf::priv::WindowImplWin32 WindowImplType;
 
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
     #include <SFML/Window/Linux/WindowImplX11.hpp>
     typedef sf::priv::WindowImplX11 WindowImplType;
