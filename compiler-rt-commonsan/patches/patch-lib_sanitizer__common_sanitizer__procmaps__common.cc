$NetBSD$

--- lib/sanitizer_common/sanitizer_procmaps_common.cc.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/sanitizer_common/sanitizer_procmaps_common.cc
@@ -12,7 +12,7 @@
 
 #include "sanitizer_platform.h"
 
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 
 #include "sanitizer_common.h"
 #include "sanitizer_placement_new.h"
@@ -173,4 +173,4 @@ void GetMemoryProfile(fill_profile_f cb,
 
 } // namespace __sanitizer
 
-#endif // SANITIZER_FREEBSD || SANITIZER_LINUX
+#endif  // SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
