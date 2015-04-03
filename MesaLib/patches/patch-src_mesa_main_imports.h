$NetBSD: patch-src_mesa_main_imports.h,v 1.3 2015/04/03 21:30:42 tnn2 Exp $

Old NetBSD doesn't have exp2.

--- src/mesa/main/imports.h.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/mesa/main/imports.h
@@ -126,6 +126,17 @@ typedef union { GLfloat f; GLint i; GLui
 #define atanhf(f) ((float) atanh(f))
 #endif
 
+#if defined(__NetBSD__) && __NetBSD_Version__ < 600000000
+#if defined(exp2f)
+#undef exp2f
+#endif
+#define exp2f(x) powf(2.0f,x)
+#if defined(exp2)
+#undef exp2
+#endif
+#define exp2(x) pow(2.0d,x)
+#endif
+
 #if defined(_MSC_VER)
 #if _MSC_VER < 1800  /* Not req'd on VS2013 and above */
 static inline float truncf(float x) { return x < 0.0f ? ceilf(x) : floorf(x); }
