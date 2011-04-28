$NetBSD: patch-base_process__util__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/process_util_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/process_util_posix.cc
@@ -102,11 +102,11 @@ int WaitpidWithTimeout(ProcessHandle han
   return status;
 }
 
-void StackDumpSignalHandler(int signal, siginfo_t* info, ucontext_t* context) {
+void StackDumpSignalHandler(int signal, siginfo_t* info /*, ucontext_t* context */) {
   LOG(ERROR) << "Received signal " << signal;
   debug::StackTrace().PrintBacktrace();
 
-  // TODO(shess): Port to Linux.
+  // TODO(shess): Port to Linux and OpenBSD.
 #if defined(OS_MACOSX)
   // TODO(shess): Port to 64-bit.
 #if ARCH_CPU_32_BITS
@@ -276,10 +276,10 @@ typedef scoped_ptr_malloc<DIR, ScopedDIR
 #elif defined(OS_SOLARIS)
   static const rlim_t kSystemDefaultMaxFds = 8192;
   static const char kFDDir[] = "/dev/fd";
-#elif defined(OS_FREEBSD)
+#elif defined(OS_FREEBSD) || defined(OS_DRAGONFLY)
   static const rlim_t kSystemDefaultMaxFds = 8192;
   static const char kFDDir[] = "/dev/fd";
-#elif defined(OS_OPENBSD)
+#elif defined(OS_OPENBSD) || defined(OS_NETBSD)
   static const rlim_t kSystemDefaultMaxFds = 256;
   static const char kFDDir[] = "/dev/fd";
 #endif
