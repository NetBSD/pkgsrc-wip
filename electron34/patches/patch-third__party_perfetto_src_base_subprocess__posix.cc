$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/perfetto/src/base/subprocess_posix.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/perfetto/src/base/subprocess_posix.cc
@@ -35,7 +35,8 @@
 #include <thread>
 #include <tuple>
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 #endif
@@ -64,7 +65,8 @@ struct ChildProcessArgs {
 // Don't add any dynamic allocation in this function. This will be invoked
 // under a fork(), potentially in a state where the allocator lock is held.
 void __attribute__((noreturn)) ChildProcess(ChildProcessArgs* args) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   // In no case we want a child process to outlive its parent process. This is
   // relevant for tests, so that a test failure/crash doesn't leave child
