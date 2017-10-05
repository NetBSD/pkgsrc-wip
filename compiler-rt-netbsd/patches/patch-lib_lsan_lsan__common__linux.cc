$NetBSD$

--- lib/lsan/lsan_common_linux.cc.orig	2017-07-20 14:23:42.000000000 +0000
+++ lib/lsan/lsan_common_linux.cc
@@ -34,7 +34,9 @@ static bool IsLinker(const char* full_na
   return LibraryNameIs(full_name, kLinkerName);
 }
 
+#if !SANITIZER_NETBSD
 __attribute__((tls_model("initial-exec")))
+#endif
 THREADLOCAL int disable_counter;
 bool DisabledInThisThread() { return disable_counter > 0; }
 void DisableInThisThread() { disable_counter++; }
