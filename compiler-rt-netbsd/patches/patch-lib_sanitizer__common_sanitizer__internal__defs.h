$NetBSD$

--- lib/sanitizer_common/sanitizer_internal_defs.h.orig	2018-02-25 10:48:27.000000000 +0000
+++ lib/sanitizer_common/sanitizer_internal_defs.h
@@ -189,7 +189,9 @@ typedef uptr tid_t;
 // This header should NOT include any other headers to avoid portability issues.
 
 // Common defs.
+#ifndef INLINE
 #define INLINE inline
+#endif
 #define INTERFACE_ATTRIBUTE SANITIZER_INTERFACE_ATTRIBUTE
 #define SANITIZER_WEAK_DEFAULT_IMPL \
   extern "C" SANITIZER_INTERFACE_ATTRIBUTE SANITIZER_WEAK_ATTRIBUTE NOINLINE
