$NetBSD$

https://github.com/google/or-tools/issues/4359

--- ortools/util/fp_utils.h.orig	2024-08-27 13:35:44.000000000 +0000
+++ ortools/util/fp_utils.h
@@ -92,10 +92,16 @@ class ScopedFloatingPointEnv {
     fenv_.__control &= ~excepts;
 #elif (defined(__FreeBSD__) || defined(__OpenBSD__))
     fenv_.__x87.__control &= ~excepts;
+#elif (defined(__NetBSD__))
+    fenv_.x87.control &= ~excepts;
 #else  // Linux
     fenv_.__control_word &= ~excepts;
 #endif
+#if defined(__NetBSD__)
+    fenv_.mxcsr &= ~(excepts << 7);
+#else
     fenv_.__mxcsr &= ~(excepts << 7);
+#endif
     CHECK_EQ(0, fesetenv(&fenv_));
 #endif
   }
