$NetBSD$

--- lib/sanitizer_common/sanitizer_libignore.cc.orig	2017-07-03 15:33:06.556851079 +0000
+++ lib/sanitizer_common/sanitizer_libignore.cc
@@ -9,7 +9,7 @@
 
 #include "sanitizer_platform.h"
 
-#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_MAC
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_MAC || SANITIZER_NETBSD
 
 #include "sanitizer_libignore.h"
 #include "sanitizer_flags.h"
@@ -125,4 +125,4 @@ void LibIgnore::OnLibraryUnloaded() {
 
 } // namespace __sanitizer
 
-#endif // #if SANITIZER_FREEBSD || SANITIZER_LINUX
+#endif // #if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
