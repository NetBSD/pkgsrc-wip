$NetBSD$

Use limits.h for NetBSD too.

--- src/doomtype.h.orig	2019-06-12 09:36:08.000000000 +0000
+++ src/doomtype.h
@@ -168,7 +168,7 @@ int strlwr(char *n);
 // Predefined with some OS.
 #ifdef __WIN32__
 #include <limits.h>
-#elif defined( MACOS_DI ) || defined( __MACH__ ) || defined( FREEBSD )
+#elif defined( MACOS_DI ) || defined( __MACH__ ) || defined( FREEBSD ) || defined( NETBSD )
 #include <limits.h>
 #else
 // Linux GNU, which also includes limits.h
