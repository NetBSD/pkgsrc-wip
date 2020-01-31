$NetBSD$

Can't re-#define int32_t; this is a reserved name.

--- htypes.h.orig	2019-09-10 18:06:20.000000000 +0000
+++ htypes.h
@@ -48,7 +48,9 @@
 
 #endif
 
+#ifndef int32_t
 #define int32_t                 int32_t         /* (used by extpkgs) */
+#endif
 
 #ifndef HAVE_U_INT8_T
   typedef uint8_t               u_int8_t;
