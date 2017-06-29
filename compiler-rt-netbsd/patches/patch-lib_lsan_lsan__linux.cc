$NetBSD$

--- lib/lsan/lsan_linux.cc.orig	2017-06-03 23:53:56.000000000 +0000
+++ lib/lsan/lsan_linux.cc
@@ -13,7 +13,7 @@
 
 #include "sanitizer_common/sanitizer_platform.h"
 
-#if SANITIZER_LINUX
+#if SANITIZER_LINUX || SANITIZER_NETBSD
 
 #include "lsan_allocator.h"
 
@@ -30,4 +30,4 @@ void ReplaceSystemMalloc() {}
 
 } // namespace __lsan
 
-#endif // SANITIZER_LINUX
+#endif // SANITIZER_LINUX || SANITIZER_NETBSD
