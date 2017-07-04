$NetBSD$

--- lib/lsan/lsan_linux.cc.orig	2017-07-04 05:53:20.000000000 +0000
+++ lib/lsan/lsan_linux.cc
@@ -30,4 +30,4 @@ void ReplaceSystemMalloc() {}
 
 } // namespace __lsan
 
-#endif // SANITIZER_LINUX
+#endif // SANITIZER_LINUX || SANITIZER_NETBSD
