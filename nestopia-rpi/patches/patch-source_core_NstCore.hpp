$NetBSD: patch-source_core_NstCore.hpp,v 1.1 2015/01/03 11:31:12 nsloss Exp $
Improve optimization with GCC with just inline.
--- source/core/NstCore.hpp.orig	2008-04-27 05:50:30.000000000 +0000
+++ source/core/NstCore.hpp
@@ -122,7 +122,7 @@
    #define NST_NO_INLINE __attribute__((noinline))
    #endif
 
-   #define NST_SINGLE_CALL __attribute__((always_inline))
+   #define NST_SINGLE_CALL inline
 
    #if (NST_GCC >= 304) && defined(__i386__)
    #define NST_REGCALL __attribute__((regparm(2)))
