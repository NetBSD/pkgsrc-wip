$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_interceptors.h.orig	2017-08-03 21:24:37.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_interceptors.h
@@ -33,7 +33,11 @@
 #endif
 
 #if SI_POSIX
-# include "sanitizer_platform_limits_posix.h"
+# if SANITIZER_NETBSD
+#  include "sanitizer_platform_limits_netbsd.h"
+# else
+#  include "sanitizer_platform_limits_posix.h"
+# endif
 #endif
 
 #if SANITIZER_LINUX && !SANITIZER_ANDROID
