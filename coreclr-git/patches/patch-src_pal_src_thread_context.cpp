$NetBSD$

--- src/pal/src/thread/context.cpp.orig	2016-02-02 22:59:18.000000000 +0000
+++ src/pal/src/thread/context.cpp
@@ -423,8 +423,12 @@ void CONTEXTToNativeContext(CONST CONTEX
     }
 #undef ASSIGN_REG
 
+#if HAVE_GREGSET_T || HAVE_GREGSET_T
 #if HAVE_GREGSET_T
     if (native->uc_mcontext.fpregs == nullptr)
+#elif HAVE___GREGSET_T
+    if (native->uc_mcontext.__fpregs == nullptr)
+#endif
     {
         // If the pointer to the floating point state in the native context
         // is not valid, we can't copy floating point registers regardless of
@@ -492,8 +496,12 @@ void CONTEXTFromNativeContext(const nati
     }
 #undef ASSIGN_REG
 
+#if HAVE_GREGSET_T || HAVE___GREGSET_T
 #if HAVE_GREGSET_T
     if (native->uc_mcontext.fpregs == nullptr)
+#elif HAVE___GREGSET_T
+    if (native->uc_mcontext.__fpregs == nullptr)
+#endif
     {
         // Reset the CONTEXT_FLOATING_POINT bit(s) so it's clear that the floating point
         // data in the CONTEXT is not valid. Since CONTEXT_FLOATING_POINT is defined as 
