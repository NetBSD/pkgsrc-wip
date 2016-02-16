$NetBSD$

--- src/pal/inc/pal.h.orig	2016-02-15 22:52:17.000000000 +0000
+++ src/pal/inc/pal.h
@@ -6340,11 +6340,6 @@ PALIMPORT char * __cdecl _strdup(const c
 #endif //_MSC_VER
 
 #if defined(__GNUC__) && defined(PLATFORM_UNIX)
-// we set -fno-builtin on the command line. This requires that if
-// we use alloca, with either have to call __builtin_alloca, or
-// ensure that the alloca call doesn't happen in code which is
-// modifying the stack (such as "memset (alloca(x), y, z)"
-
 #define alloca  __builtin_alloca
 #endif // __GNUC__
 
