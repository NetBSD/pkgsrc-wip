$NetBSD$

--- lib/sanitizer_common/sanitizer_posix.h.orig	2017-07-04 05:53:22.000000000 +0000
+++ lib/sanitizer_common/sanitizer_posix.h
@@ -16,7 +16,11 @@
 // ----------- ATTENTION -------------
 // This header should NOT include any other headers from sanitizer runtime.
 #include "sanitizer_internal_defs.h"
+#if SANITIZER_NETBSD
+#include "sanitizer_platform_limits_netbsd.h"
+#else
 #include "sanitizer_platform_limits_posix.h"
+#endif
 
 #if !SANITIZER_POSIX
 // Make it hard to accidentally use any of functions declared in this file:
