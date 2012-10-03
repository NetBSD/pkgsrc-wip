$NetBSD: patch-include_SFML_Window_WindowHandle.hpp,v 1.1 2012/10/03 15:05:59 othyro Exp $

Adds NetBSD support.

--- include/SFML/Window/WindowHandle.hpp.orig	2010-01-27 13:53:54.000000000 +0000
+++ include/SFML/Window/WindowHandle.hpp
@@ -42,7 +42,7 @@ namespace sf
     // Windows defines a void* handle (HWND)
     typedef void* WindowHandle;
 
-#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD)
+#elif defined(SFML_SYSTEM_LINUX) || defined(SFML_SYSTEM_FREEBSD) || defined(SFML_SYSTEM_NETBSD)
 
     // Unix - X11 defines an unsigned integer handle (Window)
     typedef unsigned long WindowHandle;
