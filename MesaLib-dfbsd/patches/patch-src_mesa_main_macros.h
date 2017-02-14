$NetBSD: patch-src_mesa_main_macros.h,v 1.1 2016/01/05 13:02:57 tnn Exp $

ALIGN is also defined in sys/param.h on NetBSD.

Add MESA_ALIGN for if there are still conflicts between an
OS-defined one-argument ALIGN and mesa defined two-argument ALIGN.

--- src/mesa/main/macros.h.orig	2017-02-13 11:55:49.000000000 +0000
+++ src/mesa/main/macros.h
@@ -677,11 +677,24 @@ minify(unsigned value, unsigned levels)
  *
  * \sa ROUND_DOWN_TO()
  */
+#ifdef ALIGN
+#undef ALIGN
+#endif
 static inline uintptr_t
 ALIGN(uintptr_t value, int32_t alignment)
 {
    assert((alignment > 0) && _mesa_is_pow_two(alignment));
    return (((value) + (alignment) - 1) & ~((alignment) - 1));
+}
+
+/**
+ * Like ALIGN(), but won't clash with other OSes ALIGN.
+ */
+static inline uintptr_t
+MESA_ALIGN(uintptr_t value, int32_t alignment)
+{
+   assert((alignment > 0) && _mesa_is_pow_two(alignment));
+   return (((value) + (alignment) - 1) & ~((alignment) - 1));
 }
 
 /**
