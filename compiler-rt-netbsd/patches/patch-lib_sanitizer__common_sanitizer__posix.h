$NetBSD$

--- lib/sanitizer_common/sanitizer_posix.h.orig	2017-07-04 05:53:22.000000000 +0000
+++ lib/sanitizer_common/sanitizer_posix.h
@@ -16,6 +16,7 @@
 // ----------- ATTENTION -------------
 // This header should NOT include any other headers from sanitizer runtime.
 #include "sanitizer_internal_defs.h"
+#include "sanitizer_platform_limits_netbsd.h"
 #include "sanitizer_platform_limits_posix.h"
 
 #if !SANITIZER_POSIX
