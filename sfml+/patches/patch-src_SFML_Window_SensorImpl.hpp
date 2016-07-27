$NetBSD$

--- src/SFML/Window/SensorImpl.hpp.orig	2015-08-24 16:01:06.000000000 +0000
+++ src/SFML/Window/SensorImpl.hpp
@@ -35,7 +35,7 @@
 
     #include <SFML/Window/Win32/SensorImpl.hpp>
 
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
     #include <SFML/Window/Unix/SensorImpl.hpp>
 
