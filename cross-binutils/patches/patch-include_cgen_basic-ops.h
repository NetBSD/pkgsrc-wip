$NetBSD: patch-include_cgen_basic-ops.h,v 1.1 2013/12/27 03:09:35 makoto Exp $

Derived from following patch
NetBSD: patch-opcodes_cgen-ops.h,v 1.1 2012/05/04 16:07:02 joerg Exp 
Fix inline usage.

--- include/cgen/basic-ops.h~	2013-11-05 00:33:39.000000000 +0900
+++ include/cgen/basic-ops.h	2013-12-27 11:42:45.000000000 +0900
@@ -26,7 +26,11 @@
 
 #if defined (__GNUC__) && ! defined (SEMOPS_DEFINE_INLINE)
 #define SEMOPS_DEFINE_INLINE
-#define SEMOPS_INLINE extern inline
+#  ifdef __GNUC_STDC_INLINE__
+#  define SEMOPS_INLINE static inline
+#  else
+#  define SEMOPS_INLINE extern inline
+#  endif
 #else
 #define SEMOPS_INLINE
 #endif
@@ -295,13 +299,15 @@ extern SI TRUNCDISI (DI);
    significant and word number 0 is the most significant word.
    ??? May also wish an endian-dependent version.  Later.  */
 
+#ifndef SEMOPS_DEFINE_INLINE
+
 static QI SUBWORDSIQI (SI, int);
 static HI SUBWORDSIHI (SI, int);
 static QI SUBWORDDIQI (DI, int);
 static HI SUBWORDDIHI (DI, int);
 static SI SUBWORDDISI (DI, int);
 
-#ifdef SEMOPS_DEFINE_INLINE
+#else
 
 SEMOPS_INLINE QI
 SUBWORDSIQI (SI in, int byte)
