$NetBSD$

--- src/pal/src/include/pal/palinternal.h.orig	2016-02-15 22:52:17.000000000 +0000
+++ src/pal/src/include/pal/palinternal.h
@@ -337,15 +337,15 @@ function_name() to call the system's imp
 #undef _BitScanForward64
 #endif 
 
-/* pal.h does "#define alloca _alloca", but we need access to the "real"
-   alloca */
-#undef alloca
+/* pal.h defines alloca(3) as a compiler builtin.
+   Redefining it to native libc will result in undefined breakage because
+   a compiler is allowed to make assumptions about the stack and frame
+   pointers. */
 
 /* Undef all functions and types previously defined so those functions and
    types could be mapped to the C runtime and socket implementation of the 
    native OS */
 #undef exit
-#undef alloca
 #undef atexit
 #undef div
 #undef div_t
