$NetBSD$

--- source/Plugins/Process/Linux/NativeThreadLinux.cpp.orig	2016-10-19 22:25:12.000000000 +0000
+++ source/Plugins/Process/Linux/NativeThreadLinux.cpp
@@ -29,9 +29,13 @@
 
 #include <sys/syscall.h>
 // Try to define a macro to encapsulate the tgkill syscall
+#if !defined(__NetBSD__)
 #define tgkill(pid, tid, sig)                                                  \
   syscall(__NR_tgkill, static_cast<::pid_t>(pid), static_cast<::pid_t>(tid),   \
           sig)
+#else
+#define tgkill(pid, tid, sig) 0
+#endif
 
 using namespace lldb;
 using namespace lldb_private;
@@ -97,7 +101,11 @@ std::string NativeThreadLinux::GetName()
   // const NativeProcessLinux *const process =
   // reinterpret_cast<NativeProcessLinux*> (process_sp->get ());
   llvm::SmallString<32> thread_name;
+#if !defined(__NetBSD__)
   HostNativeThread::GetName(GetID(), thread_name);
+#else
+  // error: invalid conversion from 'lldb::tid_t {aka long unsigned int}' to 'lldb::thread_t {aka __pthread_st*}' [-fpermissive]
+#endif
   return thread_name.c_str();
 }
 
@@ -216,8 +224,13 @@ Error NativeThreadLinux::Resume(uint32_t
   if (signo != LLDB_INVALID_SIGNAL_NUMBER)
     data = signo;
 
+#if !defined(__NetBSD__)
   return NativeProcessLinux::PtraceWrapper(PTRACE_CONT, GetID(), nullptr,
                                            reinterpret_cast<void *>(data));
+#else
+  Error error;
+  return error;
+#endif
 }
 
 void NativeThreadLinux::MaybePrepareSingleStepWorkaround() {
@@ -226,6 +239,7 @@ void NativeThreadLinux::MaybePrepareSing
 
   Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
 
+#if !defined(__NetBSD__)
   if (sched_getaffinity(static_cast<::pid_t>(m_tid), sizeof m_original_cpu_set,
                         &m_original_cpu_set) != 0) {
     // This should really not fail. But, just in case...
@@ -253,12 +267,14 @@ void NativeThreadLinux::MaybePrepareSing
         ": %s",
         __FUNCTION__, m_tid, error.AsCString());
   }
+#endif
 }
 
 void NativeThreadLinux::MaybeCleanupSingleStepWorkaround() {
   if (!SingleStepWorkaroundNeeded())
     return;
 
+#if !defined(__NetBSD__)
   if (sched_setaffinity(static_cast<::pid_t>(m_tid), sizeof m_original_cpu_set,
                         &m_original_cpu_set) != 0) {
     Error error(errno, eErrorTypePOSIX);
@@ -268,6 +284,7 @@ void NativeThreadLinux::MaybeCleanupSing
         ": %s",
         __FUNCTION__, m_tid, error.AsCString());
   }
+#endif
 }
 
 Error NativeThreadLinux::SingleStep(uint32_t signo) {
@@ -285,10 +302,15 @@ Error NativeThreadLinux::SingleStep(uint
   // If hardware single-stepping is not supported, we just do a continue. The
   // breakpoint on the
   // next instruction has been setup in NativeProcessLinux::Resume.
+#if !defined(__NetBSD__)
   return NativeProcessLinux::PtraceWrapper(
       GetProcess().SupportHardwareSingleStepping() ? PTRACE_SINGLESTEP
                                                    : PTRACE_CONT,
       m_tid, nullptr, reinterpret_cast<void *>(data));
+#else
+  Error error;
+  return error;
+#endif
 }
 
 void NativeThreadLinux::SetStoppedBySignal(uint32_t signo,
@@ -310,6 +332,7 @@ void NativeThreadLinux::SetStoppedBySign
     case SIGBUS:
     case SIGFPE:
     case SIGILL:
+#if !defined(__NetBSD__)
       // In case of MIPS64 target, SI_KERNEL is generated for invalid 64bit
       // address.
       const auto reason =
@@ -317,6 +340,7 @@ void NativeThreadLinux::SetStoppedBySign
               ? CrashReason::eInvalidAddress
               : GetCrashReason(*info);
       m_stop_description = GetCrashReasonString(reason, *info);
+#endif
       break;
     }
   }
@@ -440,6 +464,7 @@ Error NativeThreadLinux::RequestStop() {
 
   Error err;
   errno = 0;
+#if !defined(__NetBSD__)
   if (::tgkill(pid, tid, SIGSTOP) != 0) {
     err.SetErrorToErrno();
     if (log)
@@ -447,6 +472,7 @@ Error NativeThreadLinux::RequestStop() {
                   ", SIGSTOP) failed: %s",
                   __FUNCTION__, pid, tid, err.AsCString());
   }
+#endif
 
   return err;
 }
