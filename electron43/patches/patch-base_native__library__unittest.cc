$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/native_library_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/native_library_unittest.cc
@@ -135,7 +135,7 @@ TEST(NativeLibraryTest, LoadLibrary) {
 // versions with respect to symbol resolution scope.
 // TSan and MSan error out on RTLD_DEEPBIND, https://crbug.com/705255
 #if !BUILDFLAG(IS_ANDROID) && !defined(THREAD_SANITIZER) && \
-    !defined(MEMORY_SANITIZER)
+    !defined(MEMORY_SANITIZER) && !BUILDFLAG(IS_BSD)
 
 // Verifies that the |prefer_own_symbols| option satisfies its guarantee that
 // a loaded library will always prefer local symbol resolution before
