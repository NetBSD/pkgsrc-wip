$NetBSD$

--- lib/sanitizer_common/sanitizer_posix.cc.orig	2017-07-03 15:33:07.000000000 +0000
+++ lib/sanitizer_common/sanitizer_posix.cc
@@ -90,7 +90,9 @@ static uptr GetKernelAreaSize() {
 
 uptr GetMaxVirtualAddress() {
 #if SANITIZER_WORDSIZE == 64
-# if defined(__aarch64__) && SANITIZER_IOS && !SANITIZER_IOSSIM
+# if SANITIZER_NETBSD && defined(__x86_64__)
+  return 0x7f7ffffff000ULL;  // (0x00007f8000000000 - PAGE_SIZE)
+# elif defined(__aarch64__) && SANITIZER_IOS && !SANITIZER_IOSSIM
   // Ideally, we would derive the upper bound from MACH_VM_MAX_ADDRESS. The
   // upper bound can change depending on the device.
   return 0x200000000 - 1;
