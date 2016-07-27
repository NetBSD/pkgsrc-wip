$NetBSD$

--- src/SFML/Window/InputImpl.hpp.orig	2015-08-24 16:01:06.000000000 +0000
+++ src/SFML/Window/InputImpl.hpp
@@ -32,7 +32,7 @@
 
 #if defined(SFML_SYSTEM_WINDOWS)
     #include <SFML/Window/Win32/InputImpl.hpp>
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
     #include <SFML/Window/Unix/InputImpl.hpp>
 #elif defined(SFML_SYSTEM_MACOS)
     #include <SFML/Window/OSX/InputImpl.hpp>
