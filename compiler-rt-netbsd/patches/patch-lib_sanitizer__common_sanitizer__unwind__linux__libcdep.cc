$NetBSD$

--- lib/sanitizer_common/sanitizer_unwind_linux_libcdep.cc.orig	2018-08-21 21:25:40.000000000 +0000
+++ lib/sanitizer_common/sanitizer_unwind_linux_libcdep.cc
@@ -97,7 +97,7 @@ uptr Unwind_GetIP(struct _Unwind_Context
   // Clear the Thumb bit.
   return val & ~(uptr)1;
 #else
-  return _Unwind_GetIP(ctx);
+  return (uptr)_Unwind_GetIP(ctx);
 #endif
 }
 
