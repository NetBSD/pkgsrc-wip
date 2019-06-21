$NetBSD$

Always use limits.h.

--- src/doomtype.h.orig	2018-07-16 09:17:06.000000000 +0000
+++ src/doomtype.h
@@ -165,18 +165,31 @@ int strlwr(char *n);
 #endif
 
 
+// [WDJ] This is needs to be fixed throughout all the files.
+// But, not until it is determined which systems support which names.
 // Predefined with some OS.
 #ifdef __WIN32__
 #include <limits.h>
-#elif defined( MACOS_DI ) || defined( __MACH__ ) || defined( FREEBSD )
+#elif defined( MACOS_DI ) || defined( __MACH__ ) || defined( FREEBSD ) || defined( NETBSD )
 #include <limits.h>
 #else
 // Linux GNU, which also includes limits.h
 // obsolete header file
-#include <values.h>
-//#include <limits.h>
+//#include <values.h>
+#include <limits.h>
 #endif
 
+#if ! defined(MAXINT) && defined( INT_MAX )
+// [WDJ] Define the values.h symbols using defines from limits.h.
+// This is what values.h does now.
+#define MAXCHAR   CHAR_MAX
+#define MINCHAR   CHAR_MIN
+#define MAXSHORT  SHRT_MAX
+#define MINSHORT  SHRT_MIN
+#define MAXINT    INT_MAX
+#define MININT    INT_MIN
+
+#else
 // [WDJ] This is very dangerous considering 32 bit and 64 bit systems,
 // should use stdint.h values instead.
 // These are obsolete defines from values.h.
@@ -214,6 +227,8 @@ int strlwr(char *n);
 #define MININT    ((int)0x80000000)
 #endif
 
+#endif
+
 // Sound effect id type.
 typedef  uint16_t  sfxid_t;
 
