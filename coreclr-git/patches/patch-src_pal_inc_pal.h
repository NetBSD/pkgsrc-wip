$NetBSD$

--- src/pal/inc/pal.h.orig	2016-02-15 22:52:17.000000000 +0000
+++ src/pal/inc/pal.h
@@ -6330,23 +6330,14 @@ PALIMPORT void * __cdecl realloc(void *,
 PALIMPORT char * __cdecl _strdup(const char *);
 
 #if defined(_MSC_VER)
-#define alloca _alloca
-#elif defined(PLATFORM_UNIX)
-#define _alloca alloca
+#define Alloca _alloca
+#elif defined(__GNUC__) /* GCC-compatbile */
+// Use explicitly alloca(3) as __builtin_alloca to more strongly prevent reuse
+// of a libc version. This was required on NetBSD.
+#define Alloca __builtin_alloca
 #else
-// MingW
-#define _alloca __builtin_alloca
-#define alloca __builtin_alloca
-#endif //_MSC_VER
-
-#if defined(__GNUC__) && defined(PLATFORM_UNIX)
-// we set -fno-builtin on the command line. This requires that if
-// we use alloca, with either have to call __builtin_alloca, or
-// ensure that the alloca call doesn't happen in code which is
-// modifying the stack (such as "memset (alloca(x), y, z)"
-
-#define alloca  __builtin_alloca
-#endif // __GNUC__
+#error Port me
+#endif
 
 #define max(a, b) (((a) > (b)) ? (a) : (b))
 #define min(a, b) (((a) < (b)) ? (a) : (b))
