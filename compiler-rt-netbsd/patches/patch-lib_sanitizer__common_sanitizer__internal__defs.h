$NetBSD$

--- lib/sanitizer_common/sanitizer_internal_defs.h.orig	2018-01-15 06:00:15.000000000 +0000
+++ lib/sanitizer_common/sanitizer_internal_defs.h
@@ -177,7 +177,9 @@ typedef uptr tid_t;
 // This header should NOT include any other headers to avoid portability issues.
 
 // Common defs.
+#ifndef INLINE
 #define INLINE inline
+#endif
 #define INTERFACE_ATTRIBUTE SANITIZER_INTERFACE_ATTRIBUTE
 #define SANITIZER_WEAK_DEFAULT_IMPL \
   extern "C" SANITIZER_INTERFACE_ATTRIBUTE SANITIZER_WEAK_ATTRIBUTE NOINLINE
