$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_interceptors.h.orig	2017-08-03 21:24:37.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_interceptors.h
@@ -33,6 +33,7 @@
 #endif
 
 #if SI_POSIX
+# include "sanitizer_platform_limits_netbsd.h"
 # include "sanitizer_platform_limits_posix.h"
 #endif
 
