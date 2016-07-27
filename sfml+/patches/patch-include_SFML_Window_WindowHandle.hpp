$NetBSD$

--- include/SFML/Window/WindowHandle.hpp.orig	2015-08-24 16:01:06.000000000 +0000
+++ include/SFML/Window/WindowHandle.hpp
@@ -46,7 +46,7 @@ namespace sf
     // Window handle is HWND (HWND__*) on Windows
     typedef HWND__* WindowHandle;
 
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
     // Window handle is Window (unsigned long) on Unix - X11
     typedef unsigned long WindowHandle;
