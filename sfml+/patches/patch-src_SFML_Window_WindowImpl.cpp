$NetBSD$

--- src/SFML/Window/WindowImpl.cpp.orig	2015-08-24 16:01:06.000000000 +0000
+++ src/SFML/Window/WindowImpl.cpp
@@ -38,7 +38,7 @@
     #include <SFML/Window/Win32/WindowImplWin32.hpp>
     typedef sf::priv::WindowImplWin32 WindowImplType;
 
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
     #include <SFML/Window/Unix/WindowImplX11.hpp>
     typedef sf::priv::WindowImplX11 WindowImplType;
