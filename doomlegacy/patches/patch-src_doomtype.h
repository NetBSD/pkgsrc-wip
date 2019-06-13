$NetBSD$

Use limits.h for NetBSD too.

--- src/doomtype.h.orig	2018-07-16 09:17:06.000000000 +0000
+++ src/doomtype.h
@@ -165,17 +165,8 @@ int strlwr(char *n);
 #endif
 
 
-// Predefined with some OS.
-#ifdef __WIN32__
+// For pkgsrc: All POSIX comformant OS should have limits.h
 #include <limits.h>
-#elif defined( MACOS_DI ) || defined( __MACH__ ) || defined( FREEBSD )
-#include <limits.h>
-#else
-// Linux GNU, which also includes limits.h
-// obsolete header file
-#include <values.h>
-//#include <limits.h>
-#endif
 
 // [WDJ] This is very dangerous considering 32 bit and 64 bit systems,
 // should use stdint.h values instead.
