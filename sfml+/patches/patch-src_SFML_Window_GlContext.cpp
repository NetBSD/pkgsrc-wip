$NetBSD$

--- src/SFML/Window/GlContext.cpp.orig	2015-08-24 16:01:06.000000000 +0000
+++ src/SFML/Window/GlContext.cpp
@@ -42,7 +42,7 @@
         #include <SFML/Window/Win32/WglContext.hpp>
         typedef sf::priv::WglContext ContextType;
 
-    #elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD)
+    #elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
         #include <SFML/Window/Unix/GlxContext.hpp>
         typedef sf::priv::GlxContext ContextType;
