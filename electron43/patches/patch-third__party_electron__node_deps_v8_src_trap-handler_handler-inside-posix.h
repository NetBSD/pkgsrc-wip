$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/v8/src/trap-handler/handler-inside-posix.h.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/v8/src/trap-handler/handler-inside-posix.h
@@ -13,12 +13,12 @@ namespace v8 {
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_DARWIN
 constexpr int kOobSignal = SIGBUS;
 #else
-#error Posix trap handlers are only supported on Linux, MacOSX and FreeBSD.
+#error Posix trap handlers are only supported on Linux, MacOSX, FreeBSD, OpenBSD and NetBSD.
 #endif
 
 void HandleSignal(int signum, siginfo_t* info, void* context);
