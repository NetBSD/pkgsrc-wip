$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libc++abi/src/src/cxa_guard_impl.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/libc++abi/src/src/cxa_guard_impl.h
@@ -411,7 +411,18 @@ private:
 //                         Futex Implementation
 //===----------------------------------------------------------------------===//
 
-#if defined(SYS_futex)
+#if defined(__NetBSD__)
+void PlatformFutexWait(int* addr, int expect) {
+  constexpr int WAIT = 0;
+  syscall(SYS___futex, addr, WAIT, expect, NULL, NULL, 0, 0);
+  __tsan_acquire(addr);
+}
+void PlatformFutexWake(int* addr) {
+  constexpr int WAKE = 1;
+  __tsan_release(addr);
+  syscall(SYS___futex, addr, WAKE, INT_MAX, NULL, NULL, 0, 0);
+}
+#elif defined(SYS_futex)
 void PlatformFutexWait(int* addr, int expect) {
   constexpr int WAIT = 0;
   syscall(SYS_futex, addr, WAIT, expect, 0);
