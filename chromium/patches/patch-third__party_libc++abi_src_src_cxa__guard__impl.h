$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libc++abi/src/src/cxa_guard_impl.h.orig	2024-07-24 02:45:27.829740000 +0000
+++ third_party/libc++abi/src/src/cxa_guard_impl.h
@@ -425,6 +425,17 @@ void PlatformFutexWake(int* addr) {
   __tsan_release(addr);
   futex(reinterpret_cast<volatile uint32_t*>(addr), WAKE, INT_MAX, NULL, NULL);
 }
+#elif defined(__NetBSD__)
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
 #elif defined(SYS_futex)
 void PlatformFutexWait(int* addr, int expect) {
   constexpr int WAIT = 0;
