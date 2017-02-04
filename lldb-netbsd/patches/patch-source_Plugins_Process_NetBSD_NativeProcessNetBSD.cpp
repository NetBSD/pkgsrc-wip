$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-02-04 19:17:06.215419277 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -0,0 +1,1387 @@
+//===-- NativeProcessNetBSD.cpp -------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#include "NativeProcessNetBSD.h"
+
+// C Includes
+#include <errno.h>
+#include <stdint.h>
+#include <string.h>
+#include <unistd.h>
+
+// C++ Includes
+#include <fstream>
+#include <mutex>
+#include <sstream>
+#include <string>
+#include <unordered_map>
+
+
+// Other libraries and framework includes
+#include "lldb/Core/EmulateInstruction.h"
+#include "lldb/Utility/Error.h"
+#include "lldb/Core/ModuleSpec.h"
+#include "lldb/Core/RegisterValue.h"
+#include "lldb/Core/State.h"
+#include "lldb/Host/Host.h"
+#include "lldb/Host/HostProcess.h"
+#include "lldb/Host/ThreadLauncher.h"
+#include "lldb/Host/common/NativeBreakpoint.h"
+#include "lldb/Host/common/NativeRegisterContext.h"
+#include "lldb/Host/posix/ProcessLauncherPosixFork.h"
+#include "lldb/Symbol/ObjectFile.h"
+#include "lldb/Target/Process.h"
+#include "lldb/Target/ProcessLaunchInfo.h"
+#include "lldb/Target/Target.h"
+#include "lldb/Utility/LLDBAssert.h"
+#include "lldb/Utility/PseudoTerminal.h"
+#include "lldb/Utility/StringExtractor.h"
+
+#include "NativeThreadNetBSD.h"
+#include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
+
+// System includes - They have to be included after framework includes because
+// they define some
+// macros which collide with variable names in other modules
+#include <sys/socket.h>
+
+#include <sys/ptrace.h>
+#include <sys/syscall.h>
+#include <sys/types.h>
+#include <sys/user.h>
+#include <sys/wait.h>
+
+using namespace lldb;
+using namespace lldb_private;
+using namespace lldb_private::process_netbsd;
+using namespace llvm;
+
+namespace {
+void MaybeLogLaunchInfo(const ProcessLaunchInfo &info) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+  if (!log)
+    return;
+
+  if (const FileAction *action = info.GetFileActionForFD(STDIN_FILENO))
+    log->Printf("%s: setting STDIN to '%s'", __FUNCTION__,
+                action->GetFileSpec().GetCString());
+  else
+    log->Printf("%s leaving STDIN as is", __FUNCTION__);
+
+  if (const FileAction *action = info.GetFileActionForFD(STDOUT_FILENO))
+    log->Printf("%s setting STDOUT to '%s'", __FUNCTION__,
+                action->GetFileSpec().GetCString());
+  else
+    log->Printf("%s leaving STDOUT as is", __FUNCTION__);
+
+  if (const FileAction *action = info.GetFileActionForFD(STDERR_FILENO))
+    log->Printf("%s setting STDERR to '%s'", __FUNCTION__,
+                action->GetFileSpec().GetCString());
+  else
+    log->Printf("%s leaving STDERR as is", __FUNCTION__);
+
+  int i = 0;
+  for (const char **args = info.GetArguments().GetConstArgumentVector(); *args;
+       ++args, ++i)
+    log->Printf("%s arg %d: \"%s\"", __FUNCTION__, i,
+                *args ? *args : "nullptr");
+}
+
+void DisplayBytes(StreamString &s, void *bytes, uint32_t count) {
+  uint8_t *ptr = (uint8_t *)bytes;
+  const uint32_t loop_count = count;
+  for (uint32_t i = 0; i < loop_count; i++) {
+    s.Printf("[%x]", *ptr);
+    ptr++;
+  }
+}
+
+void PtraceDisplayBytes(int &req, void *addr, int data) {
+  StreamString buf;
+  Log *verbose_log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(
+      POSIX_LOG_PTRACE | POSIX_LOG_VERBOSE));
+
+  if (verbose_log) {
+    switch (req) {
+    case PT_WRITE_I: {
+      DisplayBytes(buf, &data, sizeof(int));
+      verbose_log->Printf("PT_WRITE_I %s", buf.GetData());
+      break;
+    }
+    case PT_WRITE_D: {
+      DisplayBytes(buf, &data, sizeof(int));
+      verbose_log->Printf("PT_WRITE_I %s", buf.GetData());
+      break;
+    }
+#ifdef PT_SETREGS
+    case PT_SETREGS: {
+      DisplayBytes(buf, addr, sizeof(struct reg));
+      verbose_log->Printf("PT_SETREGS %s", buf.GetData());
+      break;
+    }
+#endif
+#ifdef PT_SETFPREGS
+    case PT_SETFPREGS: {
+      DisplayBytes(buf, addr, sizeof(struct fpreg));
+      verbose_log->Printf("PT_SETFPREGS %s", buf.GetData());
+      break;
+    }
+#endif
+#ifdef PT_SETXMMREGS
+    case PT_SETXMMREGS: {
+      DisplayBytes(buf, addr, sizeof(struct xmmregs));
+      verbose_log->Printf("PT_SETXMMREGS %s", buf.GetData());
+      break;
+    }
+#endif
+#ifdef PT_SETVECREGS
+    case PT_SETVECREGS: {
+      DisplayBytes(buf, addr, sizeof(struct vreg));
+      verbose_log->Printf("PT_SETVECREGS %s", buf.GetData());
+      break;
+    }
+#endif
+    default: {}
+    }
+  }
+}
+
+static constexpr unsigned k_ptrace_word_size = sizeof(void *);
+static_assert(sizeof(long) >= k_ptrace_word_size,
+              "Size of long must be larger than ptrace word size");
+} // end of anonymous namespace
+
+// Simple helper function to ensure flags are enabled on the given file
+// descriptor.
+static Error EnsureFDFlags(int fd, int flags) {
+  Error error;
+
+  int status = fcntl(fd, F_GETFL);
+  if (status == -1) {
+    error.SetErrorToErrno();
+    return error;
+  }
+
+  if (fcntl(fd, F_SETFL, status | flags) == -1) {
+    error.SetErrorToErrno();
+    return error;
+  }
+
+  return error;
+}
+
+// -----------------------------------------------------------------------------
+// Public Static Methods
+// -----------------------------------------------------------------------------
+
+Error NativeProcessProtocol::Launch(
+    ProcessLaunchInfo &launch_info,
+    NativeProcessProtocol::NativeDelegate &native_delegate, MainLoop &mainloop,
+    NativeProcessProtocolSP &native_process_sp) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+
+  Error error;
+
+  // Verify the working directory is valid if one was specified.
+  FileSpec working_dir{launch_info.GetWorkingDirectory()};
+  if (working_dir &&
+      (!working_dir.ResolvePath() ||
+       working_dir.GetFileType() != FileSpec::eFileTypeDirectory)) {
+    error.SetErrorStringWithFormat("No such file or directory: %s",
+                                   working_dir.GetCString());
+    return error;
+  }
+
+  // Create the NativeProcessNetBSD in launch mode.
+  native_process_sp.reset(new NativeProcessNetBSD());
+
+  if (!native_process_sp->RegisterNativeDelegate(native_delegate)) {
+    native_process_sp.reset();
+    error.SetErrorStringWithFormat("failed to register the native delegate");
+    return error;
+  }
+
+  error = std::static_pointer_cast<NativeProcessNetBSD>(native_process_sp)
+              ->LaunchInferior(mainloop, launch_info);
+
+  if (error.Fail()) {
+    native_process_sp.reset();
+    if (log)
+      log->Printf("NativeProcessNetBSD::%s failed to launch process: %s",
+                  __FUNCTION__, error.AsCString());
+    return error;
+  }
+
+  launch_info.SetProcessID(native_process_sp->GetID());
+
+  return error;
+}
+
+Error NativeProcessProtocol::Attach(
+    lldb::pid_t pid, NativeProcessProtocol::NativeDelegate &native_delegate,
+    MainLoop &mainloop, NativeProcessProtocolSP &native_process_sp) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+  if (log && log->GetMask().Test(POSIX_LOG_VERBOSE))
+    log->Printf("NativeProcessNetBSD::%s(pid = %" PRIi64 ")", __FUNCTION__, pid);
+
+  // Retrieve the architecture for the running process.
+  ArchSpec process_arch;
+  Error error = ResolveProcessArchitecture(pid, process_arch);
+  if (!error.Success())
+    return error;
+
+  std::shared_ptr<NativeProcessNetBSD> native_process_netbsd_sp(
+      new NativeProcessNetBSD());
+
+  if (!native_process_netbsd_sp->RegisterNativeDelegate(native_delegate)) {
+    error.SetErrorStringWithFormat("failed to register the native delegate");
+    return error;
+  }
+
+  native_process_netbsd_sp->AttachToInferior(mainloop, pid, error);
+  if (!error.Success())
+    return error;
+
+  native_process_sp = native_process_netbsd_sp;
+  return error;
+}
+
+// -----------------------------------------------------------------------------
+// Public Instance Methods
+// -----------------------------------------------------------------------------
+
+NativeProcessNetBSD::NativeProcessNetBSD()
+    : NativeProcessProtocol(LLDB_INVALID_PROCESS_ID), m_arch(),
+      m_supports_mem_region(eLazyBoolCalculate), m_mem_region_cache(),
+      m_pending_notification_tid(LLDB_INVALID_THREAD_ID) {}
+
+void NativeProcessNetBSD::AttachToInferior(MainLoop &mainloop, lldb::pid_t pid,
+                                          Error &error) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s (pid = %" PRIi64 ")", __FUNCTION__,
+                pid);
+
+  m_sigchld_handle = mainloop.RegisterSignal(
+      SIGCHLD, [this](MainLoopBase &) { SigchldHandler(); }, error);
+  if (!m_sigchld_handle)
+    return;
+
+  error = ResolveProcessArchitecture(pid, m_arch);
+  if (!error.Success())
+    return;
+
+  // Set the architecture to the exe architecture.
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s (pid = %" PRIi64
+                ") detected architecture %s",
+                __FUNCTION__, pid, m_arch.GetArchitectureName());
+
+  m_pid = pid;
+  SetState(eStateAttaching);
+
+  Attach(pid, error);
+}
+
+Error NativeProcessNetBSD::LaunchInferior(MainLoop &mainloop,
+                                         ProcessLaunchInfo &launch_info) {
+  Error error;
+  m_sigchld_handle = mainloop.RegisterSignal(
+      SIGCHLD, [this](MainLoopBase &) { SigchldHandler(); }, error);
+  if (!m_sigchld_handle)
+    return error;
+
+  SetState(eStateLaunching);
+
+  MaybeLogLaunchInfo(launch_info);
+
+  ::pid_t pid =
+      ProcessLauncherPosixFork().LaunchProcess(launch_info, error).GetProcessId();
+  if (error.Fail())
+    return error;
+
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+
+  // Wait for the child process to trap on its call to execve.
+  ::pid_t wpid;
+  int status;
+  if ((wpid = waitpid(pid, &status, 0)) < 0) {
+    error.SetErrorToErrno();
+    if (log)
+      log->Printf("NativeProcessNetBSD::%s waitpid for inferior failed with %s",
+                  __FUNCTION__, error.AsCString());
+
+    // Mark the inferior as invalid.
+    // FIXME this could really use a new state - eStateLaunchFailure.  For now,
+    // using eStateInvalid.
+    SetState(StateType::eStateInvalid);
+
+    return error;
+  }
+  assert(WIFSTOPPED(status) && (wpid == static_cast<::pid_t>(pid)) &&
+         "Could not sync with inferior process.");
+
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s inferior started, now in stopped state",
+                __FUNCTION__);
+
+  SetDefaultPtraceOpts(pid);
+
+  // Release the master terminal descriptor and pass it off to the
+  // NativeProcessNetBSD instance.  Similarly stash the inferior pid.
+  m_terminal_fd = launch_info.GetPTY().ReleaseMasterFileDescriptor();
+  m_pid = pid;
+  launch_info.SetProcessID(pid);
+
+  if (m_terminal_fd != -1) {
+    error = EnsureFDFlags(m_terminal_fd, O_NONBLOCK);
+    if (error.Fail()) {
+      if (log)
+        log->Printf("NativeProcessNetBSD::%s inferior EnsureFDFlags failed for "
+                    "ensuring terminal O_NONBLOCK setting: %s",
+                    __FUNCTION__, error.AsCString());
+
+      // Mark the inferior as invalid.
+      // FIXME this could really use a new state - eStateLaunchFailure.  For
+      // now, using eStateInvalid.
+      SetState(StateType::eStateInvalid);
+
+      return error;
+    }
+  }
+
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s() adding pid = %" PRIu64, __FUNCTION__,
+                uint64_t(pid));
+
+  ResolveProcessArchitecture(m_pid, m_arch);
+
+  /* Initialize threads */
+  struct ptrace_lwpinfo info = {};
+  error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+  if (error.Fail()) {
+    SetState(StateType::eStateInvalid);
+    return error;
+  }
+  while (info.pl_lwpid != 0) {
+    NativeThreadNetBSDSP thread_sp = AddThread(info.pl_lwpid);
+    thread_sp->SetStoppedBySignal(SIGSTOP);
+    error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+    if (error.Fail()) {
+      SetState(StateType::eStateInvalid);
+      return error;
+    }
+  }
+
+  /* Set process stopped */
+  SetState(StateType::eStateStopped);
+
+  if (log) {
+    if (error.Success())
+      log->Printf("NativeProcessNetBSD::%s inferior launching succeeded",
+                  __FUNCTION__);
+    else
+      log->Printf("NativeProcessNetBSD::%s inferior launching failed: %s",
+                  __FUNCTION__, error.AsCString());
+  }
+  return error;
+}
+
+::pid_t NativeProcessNetBSD::Attach(lldb::pid_t pid, Error &error) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+
+  // Use a map to keep track of the threads which we have attached/need to
+  // attach.
+  Host::TidMap tids_to_attach;
+  if (pid <= 1) {
+    error.SetErrorToGenericError();
+    error.SetErrorString("Attaching to process 1 is not allowed.");
+    return -1;
+  }
+
+  // Attach to the requested process.
+  // An attach will cause the thread to stop with a SIGSTOP.
+  error = PtraceWrapper(PT_ATTACH, pid);
+  if (error.Fail())
+    return -1;
+
+  int status;
+  // Need to use WALLSIG otherwise we receive an error with errno=ECHLD
+  // At this point we should have a thread stopped if waitpid succeeds.
+  if ((status = waitpid(pid, NULL, WALLSIG)) < 0)
+    return -1;
+
+  SetDefaultPtraceOpts(pid);
+
+  m_pid = pid;
+
+  /* Initialize threads */
+  struct ptrace_lwpinfo info = {};
+  error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+  if (error.Fail()) {
+    SetState(StateType::eStateInvalid);
+    return -1;
+  }
+  while (info.pl_lwpid != 0) {
+    NativeThreadNetBSDSP thread_sp = AddThread(info.pl_lwpid);
+    thread_sp->SetStoppedBySignal(SIGSTOP);
+    error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+    if (error.Fail()) {
+      SetState(StateType::eStateInvalid);
+      return -1;
+    }
+  }
+
+  // Let our process instance know the thread has stopped.
+  SetState(StateType::eStateStopped);
+
+  return pid;
+}
+
+Error NativeProcessNetBSD::SetDefaultPtraceOpts(lldb::pid_t pid) {
+  ptrace_event_t event = {};
+
+#if notyet
+  // Report forks
+  event.pe_set_event |= PTRACE_FORK;
+
+  // Report vforks
+  // TODO: Currently unsupported in NetBSD
+  event.pe_set_event |= PTRACE_VFORK;
+
+  // Report finished vforks - the parent unblocked after execve(2) or exit(2) of the child
+  event.pe_set_event |= PTRACE_VFORK_DONE;
+#endif
+
+  // Report LWP (thread) creation
+  event.pe_set_event |= PTRACE_LWP_CREATE;
+
+  // Report LWP (thread) termination
+  event.pe_set_event |= PTRACE_LWP_EXIT;
+
+  return PtraceWrapper(PT_SET_EVENT_MASK, pid, &event, sizeof(struct ptrace_event));
+}
+
+static ExitType convert_pid_status_to_exit_type(int status) {
+  if (WIFEXITED(status))
+    return ExitType::eExitTypeExit;
+  else if (WIFSIGNALED(status))
+    return ExitType::eExitTypeSignal;
+  else if (WIFSTOPPED(status))
+    return ExitType::eExitTypeStop;
+  else {
+    // We don't know what this is.
+    return ExitType::eExitTypeInvalid;
+  }
+}
+
+static int convert_pid_status_to_return_code(int status) {
+  if (WIFEXITED(status))
+    return WEXITSTATUS(status);
+  else if (WIFSIGNALED(status))
+    return WTERMSIG(status);
+  else if (WIFSTOPPED(status))
+    return WSTOPSIG(status);
+  else {
+    // We don't know what this is.
+    return ExitType::eExitTypeInvalid;
+  }
+}
+
+// Handles all waitpid events from the inferior process.
+void NativeProcessNetBSD::MonitorCallback(lldb::pid_t pid, bool exited,
+                                         int signal, int status) {
+  Log *log(GetLogIfAnyCategoriesSet(LIBLLDB_LOG_PROCESS));
+
+  // Handle when the process exits.
+  if (exited) {
+    if (log)
+      log->Printf(
+          "NativeProcessNetBSD::%s() got exit signal(%d) , pid = %d",
+          __FUNCTION__, signal, pid);
+
+    /* Stop Tracking All Threads attached to Process */
+    m_threads.clear();
+
+    SetExitStatus(convert_pid_status_to_exit_type(status),
+                  convert_pid_status_to_return_code(status), nullptr, true);
+
+    // Notify delegate that our process has exited.
+    SetState(StateType::eStateExited, true);
+
+    return;
+  }
+
+  ptrace_siginfo_t info;
+  const auto siginfo_err = PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
+
+  ptrace_state_t state;
+  const auto state_err = PtraceWrapper(PT_GET_PROCESS_STATE, pid, &state, sizeof(state));
+
+  printf("Signal received signo=%d errno=%d code=%d\n", info.psi_siginfo.si_signo,
+    info.psi_siginfo.si_errno, info.psi_siginfo.si_code);
+
+  // Get details on the signal raised.
+  if (siginfo_err.Success() && state_err.Success()) {
+    switch (info.psi_siginfo.si_signo) {
+    case SIGTRAP:
+      switch (info.psi_siginfo.si_code) {
+      case TRAP_BRKPT:
+        for (const auto &thread_sp : m_threads) {
+          static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByBreakpoint();
+        }
+        SetState(StateType::eStateStopped, true);
+        break;
+      case TRAP_TRACE:
+        for (const auto &thread_sp : m_threads) {
+          static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByTrace();
+        }
+        SetState(StateType::eStateStopped, true);
+        break;
+      case TRAP_EXEC:
+        {
+        // Clear old threads
+        m_threads.clear();
+
+        // Initialize new thread
+        struct ptrace_lwpinfo info = {};
+        Error error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+        if (error.Fail()) {
+          SetState(StateType::eStateInvalid);
+          return;
+        }
+
+        // Reinitialize from scratch threads and register them in process
+        while (info.pl_lwpid != 0) {
+          NativeThreadNetBSDSP thread_sp = AddThread(info.pl_lwpid);
+          thread_sp->SetStoppedByExec();
+          error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+          if (error.Fail()) {
+            SetState(StateType::eStateInvalid);
+            return;
+          }
+        }
+
+        // Let our delegate know we have just exec'd.
+        NotifyDidExec();
+
+        SetState(StateType::eStateStopped, true);
+        }
+        break;
+      case TRAP_CHLD:
+        {
+        // fork(2)
+        if ((state.pe_report_event & PTRACE_FORK) != 0)
+          printf("Fork reported\n");
+        // vfork(2)
+        else if ((state.pe_report_event & PTRACE_VFORK) != 0)
+          printf("VFork reported\n");
+        // vfork(2) done
+        else if ((state.pe_report_event & PTRACE_VFORK_DONE) != 0)
+          printf("VFork Done reported\n");
+        }
+        break;
+      case TRAP_LWP:
+        {
+        // _lwp_create(2)
+        if ((state.pe_report_event & PTRACE_LWP_CREATE) != 0) {
+          AddThread(state.pe_lwp);
+          for (const auto &thread_sp : m_threads) {
+            static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(info.psi_siginfo.si_signo, &info.psi_siginfo);
+          }
+        }
+        // _lwp_exit(2)
+        if ((state.pe_report_event & PTRACE_LWP_EXIT) != 0)
+          for (size_t i; i < m_threads.size(); i++) {
+            if (static_pointer_cast<NativeThreadNetBSD>(m_threads[i])->GetID() == state.pe_lwp) {
+              m_threads.erase(m_threads.begin() + i);
+              break;
+            }
+          }
+          for (const auto &thread_sp : m_threads) {
+            static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(info.psi_siginfo.si_signo, &info.psi_siginfo);
+          }
+        }
+        SetState(StateType::eStateStopped, true);
+        break;
+      case TRAP_HWWPT:
+        printf("hw watchpoint reported\n");
+        break;
+      }
+    case SIGSTOP:
+      // Handle SIGSTOP from LLGS (LLDB GDB Server)
+      if (info.psi_siginfo.si_code == SI_USER && info.psi_siginfo.si_pid == ::getpid()) {
+        /* Stop Tracking All Threads attached to Process */
+        for (const auto &thread_sp : m_threads) {
+          static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(SIGSTOP, &info.psi_siginfo);
+        }
+      }
+    default:
+      // Other signals
+      for (const auto &thread_sp : m_threads) {
+        static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(info.psi_siginfo.si_signo, &info.psi_siginfo);
+      }
+      SetState(StateType::eStateStopped, true);
+    }
+  }
+}
+
+namespace {
+
+struct EmulatorBaton {
+  NativeProcessNetBSD *m_process;
+  NativeRegisterContext *m_reg_context;
+
+  // eRegisterKindDWARF -> RegsiterValue
+  std::unordered_map<uint32_t, RegisterValue> m_register_values;
+
+  EmulatorBaton(NativeProcessNetBSD *process, NativeRegisterContext *reg_context)
+      : m_process(process), m_reg_context(reg_context) {}
+};
+
+} // anonymous namespace
+
+static size_t ReadMemoryCallback(EmulateInstruction *instruction, void *baton,
+                                 const EmulateInstruction::Context &context,
+                                 lldb::addr_t addr, void *dst, size_t length) {
+  EmulatorBaton *emulator_baton = static_cast<EmulatorBaton *>(baton);
+
+  size_t bytes_read;
+  emulator_baton->m_process->ReadMemory(addr, dst, length, bytes_read);
+  return bytes_read;
+}
+
+static bool ReadRegisterCallback(EmulateInstruction *instruction, void *baton,
+                                 const RegisterInfo *reg_info,
+                                 RegisterValue &reg_value) {
+  EmulatorBaton *emulator_baton = static_cast<EmulatorBaton *>(baton);
+
+  auto it = emulator_baton->m_register_values.find(
+      reg_info->kinds[eRegisterKindDWARF]);
+  if (it != emulator_baton->m_register_values.end()) {
+    reg_value = it->second;
+    return true;
+  }
+
+  // The emulator only fill in the dwarf regsiter numbers (and in some case
+  // the generic register numbers). Get the full register info from the
+  // register context based on the dwarf register numbers.
+  const RegisterInfo *full_reg_info =
+      emulator_baton->m_reg_context->GetRegisterInfo(
+          eRegisterKindDWARF, reg_info->kinds[eRegisterKindDWARF]);
+
+  Error error =
+      emulator_baton->m_reg_context->ReadRegister(full_reg_info, reg_value);
+  if (error.Success())
+    return true;
+
+  return false;
+}
+
+static bool WriteRegisterCallback(EmulateInstruction *instruction, void *baton,
+                                  const EmulateInstruction::Context &context,
+                                  const RegisterInfo *reg_info,
+                                  const RegisterValue &reg_value) {
+  EmulatorBaton *emulator_baton = static_cast<EmulatorBaton *>(baton);
+  emulator_baton->m_register_values[reg_info->kinds[eRegisterKindDWARF]] =
+      reg_value;
+  return true;
+}
+
+static size_t WriteMemoryCallback(EmulateInstruction *instruction, void *baton,
+                                  const EmulateInstruction::Context &context,
+                                  lldb::addr_t addr, const void *dst,
+                                  size_t length) {
+  return length;
+}
+
+static lldb::addr_t ReadFlags(NativeRegisterContext *regsiter_context) {
+  const RegisterInfo *flags_info = regsiter_context->GetRegisterInfo(
+      eRegisterKindGeneric, LLDB_REGNUM_GENERIC_FLAGS);
+  return regsiter_context->ReadRegisterAsUnsigned(flags_info,
+                                                  LLDB_INVALID_ADDRESS);
+}
+
+Error NativeProcessNetBSD::Resume(const ResumeActionList &resume_actions) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS | LIBLLDB_LOG_THREAD));
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s called: pid %d", __FUNCTION__,
+                GetID());
+
+  const auto &thread_sp = m_threads[0];
+  const ResumeAction *const action = resume_actions.GetActionForThread(thread_sp->GetID(), true);
+
+  if (action == nullptr) {
+    if (log)
+      log->Printf("NativeProcessLinux::%s no action specified for pid %" PRIu64 " tid %" PRIu64,
+                  __FUNCTION__, GetID(), thread_sp->GetID());
+     return Error();
+  }
+
+  switch (action->state) {
+  case eStateRunning: {
+    // Run the thread, possibly feeding it the signal.
+    Error error = NativeProcessNetBSD::PtraceWrapper(PT_CONTINUE, GetID(),(void *)1, action->signal);
+    if (!error.Success())
+      return error;
+    for (const auto &thread_sp : m_threads) {
+      static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetRunning();
+    }
+    SetState(eStateRunning, true);
+    break;
+  }
+  case eStateStepping: {
+    // Run the thread, possibly feeding it the signal.
+    Error error = NativeProcessNetBSD::PtraceWrapper(PT_STEP, GetID(),(void *)1, action->signal);
+    if (!error.Success())
+      return error;
+    for (const auto &thread_sp : m_threads) {
+      static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStepping();
+    }
+    SetState(eStateStepping, true);
+    break;
+  }
+
+  case eStateSuspended:
+  case eStateStopped:
+    lldbassert(0 && "Unexpected state");
+ 
+  default:
+    return Error("NativeProcessLinux::%s (): unexpected state %s specified "
+                 "for pid %" PRIu64 ", tid %" PRIu64,
+                 __FUNCTION__, StateAsCString(action->state), GetID(),
+                 thread_sp->GetID());
+  }
+
+  return Error();
+}
+
+Error NativeProcessNetBSD::Halt() {
+  Error error;
+
+  if (kill(GetID(), SIGSTOP) != 0)
+    error.SetErrorToErrno();
+
+  return error;
+}
+
+Error NativeProcessNetBSD::Detach() {
+  Error error;
+
+  // Stop monitoring the inferior.
+  m_sigchld_handle.reset();
+
+  // Tell ptrace to detach from the process.
+  if (GetID() == LLDB_INVALID_PROCESS_ID)
+    return error;
+
+  return PtraceWrapper(PT_DETACH, GetID());
+}
+
+Error NativeProcessNetBSD::Signal(int signo) {
+  Error error;
+
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+  if (log)
+    log->Printf(
+        "NativeProcessNetBSD::%s: sending signal %d (%s) to pid %" PRIu64,
+        __FUNCTION__, signo, Host::GetSignalAsCString(signo), GetID());
+
+  if (kill(GetID(), signo))
+    error.SetErrorToErrno();
+
+  return error;
+}
+
+Error NativeProcessNetBSD::Interrupt() {
+  // Pick a running thread (or if none, a not-dead stopped thread) as
+  // the chosen thread that will be the stop-reason thread.
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+
+  NativeThreadProtocolSP running_thread_sp;
+  NativeThreadProtocolSP stopped_thread_sp;
+
+  if (log)
+    log->Printf(
+        "NativeProcessNetBSD::%s selecting running thread for interrupt target",
+        __FUNCTION__);
+
+  for (auto thread_sp : m_threads) {
+    // The thread shouldn't be null but lets just cover that here.
+    if (!thread_sp)
+      continue;
+
+    // If we have a running or stepping thread, we'll call that the
+    // target of the interrupt.
+    const auto thread_state = thread_sp->GetState();
+    if (thread_state == eStateRunning || thread_state == eStateStepping) {
+      running_thread_sp = thread_sp;
+      break;
+    } else if (!stopped_thread_sp && StateIsStoppedState(thread_state, true)) {
+      // Remember the first non-dead stopped thread.  We'll use that as a backup
+      // if there are no running threads.
+      stopped_thread_sp = thread_sp;
+    }
+  }
+
+  if (!running_thread_sp && !stopped_thread_sp) {
+    Error error("found no running/stepping or live stopped threads as target "
+                "for interrupt");
+    if (log)
+      log->Printf("NativeProcessNetBSD::%s skipping due to error: %s",
+                  __FUNCTION__, error.AsCString());
+
+    return error;
+  }
+
+  NativeThreadProtocolSP deferred_signal_thread_sp =
+      running_thread_sp ? running_thread_sp : stopped_thread_sp;
+
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s pid %" PRIu64 " %s tid %" PRIu64
+                " chosen for interrupt target",
+                __FUNCTION__, GetID(),
+                running_thread_sp ? "running" : "stopped",
+                deferred_signal_thread_sp->GetID());
+
+  return Error();
+}
+
+Error NativeProcessNetBSD::Kill() {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s called for PID %" PRIu64, __FUNCTION__,
+                GetID());
+
+  Error error;
+
+  switch (m_state) {
+  case StateType::eStateInvalid:
+  case StateType::eStateExited:
+  case StateType::eStateCrashed:
+  case StateType::eStateDetached:
+  case StateType::eStateUnloaded:
+    // Nothing to do - the process is already dead.
+    if (log)
+      log->Printf("NativeProcessNetBSD::%s ignored for PID %" PRIu64
+                  " due to current state: %s",
+                  __FUNCTION__, GetID(), StateAsCString(m_state));
+    return error;
+
+  case StateType::eStateConnected:
+  case StateType::eStateAttaching:
+  case StateType::eStateLaunching:
+  case StateType::eStateStopped:
+  case StateType::eStateRunning:
+  case StateType::eStateStepping:
+  case StateType::eStateSuspended:
+    // We can try to kill a process in these states.
+    break;
+  }
+
+  if (kill(GetID(), SIGKILL) != 0) {
+    error.SetErrorToErrno();
+    return error;
+  }
+
+  return error;
+}
+
+static Error
+ParseMemoryRegionInfoFromProcMapsLine(const std::string &maps_line,
+                                      MemoryRegionInfo &memory_region_info) {
+  memory_region_info.Clear();
+
+  StringExtractor line_extractor(maps_line.c_str());
+
+  // Format: {address_start_hex}-{address_end_hex} perms offset  dev   inode
+  // pathname
+  // perms: rwxp   (letter is present if set, '-' if not, final character is
+  // p=private, s=shared).
+
+  // Parse out the starting address
+  lldb::addr_t start_address = line_extractor.GetHexMaxU64(false, 0);
+
+  // Parse out hyphen separating start and end address from range.
+  if (!line_extractor.GetBytesLeft() || (line_extractor.GetChar() != '-'))
+    return Error(
+        "malformed /proc/{pid}/maps entry, missing dash between address range");
+
+  // Parse out the ending address
+  lldb::addr_t end_address = line_extractor.GetHexMaxU64(false, start_address);
+
+  // Parse out the space after the address.
+  if (!line_extractor.GetBytesLeft() || (line_extractor.GetChar() != ' '))
+    return Error("malformed /proc/{pid}/maps entry, missing space after range");
+
+  // Save the range.
+  memory_region_info.GetRange().SetRangeBase(start_address);
+  memory_region_info.GetRange().SetRangeEnd(end_address);
+
+  // Any memory region in /proc/{pid}/maps is by definition mapped into the
+  // process.
+  memory_region_info.SetMapped(MemoryRegionInfo::OptionalBool::eYes);
+
+  // Parse out each permission entry.
+  if (line_extractor.GetBytesLeft() < 4)
+    return Error("malformed /proc/{pid}/maps entry, missing some portion of "
+                 "permissions");
+
+  // Handle read permission.
+  const char read_perm_char = line_extractor.GetChar();
+  if (read_perm_char == 'r')
+    memory_region_info.SetReadable(MemoryRegionInfo::OptionalBool::eYes);
+  else if (read_perm_char == '-')
+    memory_region_info.SetReadable(MemoryRegionInfo::OptionalBool::eNo);
+  else
+    return Error("unexpected /proc/{pid}/maps read permission char");
+
+  // Handle write permission.
+  const char write_perm_char = line_extractor.GetChar();
+  if (write_perm_char == 'w')
+    memory_region_info.SetWritable(MemoryRegionInfo::OptionalBool::eYes);
+  else if (write_perm_char == '-')
+    memory_region_info.SetWritable(MemoryRegionInfo::OptionalBool::eNo);
+  else
+    return Error("unexpected /proc/{pid}/maps write permission char");
+
+  // Handle execute permission.
+  const char exec_perm_char = line_extractor.GetChar();
+  if (exec_perm_char == 'x')
+    memory_region_info.SetExecutable(MemoryRegionInfo::OptionalBool::eYes);
+  else if (exec_perm_char == '-')
+    memory_region_info.SetExecutable(MemoryRegionInfo::OptionalBool::eNo);
+  else
+    return Error("unexpected /proc/{pid}/maps exec permission char");
+
+  line_extractor.GetChar();              // Read the private bit
+  line_extractor.SkipSpaces();           // Skip the separator
+  line_extractor.GetHexMaxU64(false, 0); // Read the offset
+  line_extractor.GetHexMaxU64(false, 0); // Read the major device number
+  line_extractor.GetChar();              // Read the device id separator
+  line_extractor.GetHexMaxU64(false, 0); // Read the major device number
+  line_extractor.SkipSpaces();           // Skip the separator
+  line_extractor.GetU64(0, 10);          // Read the inode number
+
+  line_extractor.SkipSpaces();
+  const char *name = line_extractor.Peek();
+  if (name)
+    memory_region_info.SetName(name);
+
+  return Error();
+}
+
+Error NativeProcessNetBSD::GetMemoryRegionInfo(lldb::addr_t load_addr,
+                                              MemoryRegionInfo &range_info) {
+  // FIXME review that the final memory region returned extends to the end of
+  // the virtual address space,
+  // with no perms if it is not mapped.
+
+  // Use an approach that reads memory regions from /proc/{pid}/maps.
+  // Assume proc maps entries are in ascending order.
+  // FIXME assert if we find differently.
+
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+  Error error;
+
+  if (m_supports_mem_region == LazyBool::eLazyBoolNo) {
+    // We're done.
+    error.SetErrorString("unsupported");
+    return error;
+  }
+
+ {
+    if (log)
+      log->Printf("NativeProcessNetBSD::%s reusing %" PRIu64
+                  " cached memory region entries",
+                  __FUNCTION__,
+                  static_cast<uint64_t>(m_mem_region_cache.size()));
+  }
+
+  lldb::addr_t prev_base_address = 0;
+
+  // FIXME start by finding the last region that is <= target address using
+  // binary search.  Data is sorted.
+  // There can be a ton of regions on pthreads apps with lots of threads.
+  for (auto it = m_mem_region_cache.begin(); it != m_mem_region_cache.end();
+       ++it) {
+    MemoryRegionInfo &proc_entry_info = *it;
+
+    // Sanity check assumption that /proc/{pid}/maps entries are ascending.
+    assert((proc_entry_info.GetRange().GetRangeBase() >= prev_base_address) &&
+           "descending /proc/pid/maps entries detected, unexpected");
+    prev_base_address = proc_entry_info.GetRange().GetRangeBase();
+
+    // If the target address comes before this entry, indicate distance to next
+    // region.
+    if (load_addr < proc_entry_info.GetRange().GetRangeBase()) {
+      range_info.GetRange().SetRangeBase(load_addr);
+      range_info.GetRange().SetByteSize(
+          proc_entry_info.GetRange().GetRangeBase() - load_addr);
+      range_info.SetReadable(MemoryRegionInfo::OptionalBool::eNo);
+      range_info.SetWritable(MemoryRegionInfo::OptionalBool::eNo);
+      range_info.SetExecutable(MemoryRegionInfo::OptionalBool::eNo);
+      range_info.SetMapped(MemoryRegionInfo::OptionalBool::eNo);
+
+      return error;
+    } else if (proc_entry_info.GetRange().Contains(load_addr)) {
+      // The target address is within the memory region we're processing here.
+      range_info = proc_entry_info;
+      return error;
+    }
+
+    // The target memory address comes somewhere after the region we just
+    // parsed.
+  }
+
+  // If we made it here, we didn't find an entry that contained the given
+  // address. Return the
+  // load_addr as start and the amount of bytes betwwen load address and the end
+  // of the memory as
+  // size.
+  range_info.GetRange().SetRangeBase(load_addr);
+  range_info.GetRange().SetRangeEnd(LLDB_INVALID_ADDRESS);
+  range_info.SetReadable(MemoryRegionInfo::OptionalBool::eNo);
+  range_info.SetWritable(MemoryRegionInfo::OptionalBool::eNo);
+  range_info.SetExecutable(MemoryRegionInfo::OptionalBool::eNo);
+  range_info.SetMapped(MemoryRegionInfo::OptionalBool::eNo);
+  return error;
+}
+
+void NativeProcessNetBSD::DoStopIDBumped(uint32_t newBumpId) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s(newBumpId=%" PRIu32 ") called",
+                __FUNCTION__, newBumpId);
+
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s clearing %" PRIu64
+                " entries from the cache",
+                __FUNCTION__, static_cast<uint64_t>(m_mem_region_cache.size()));
+  m_mem_region_cache.clear();
+}
+
+Error NativeProcessNetBSD::AllocateMemory(size_t size, uint32_t permissions,
+                                         lldb::addr_t &addr) {
+// FIXME implementing this requires the equivalent of
+// InferiorCallPOSIX::InferiorCallMmap, which depends on
+// functional ThreadPlans working with Native*Protocol.
+#if 1
+  return Error("not implemented yet");
+#else
+  addr = LLDB_INVALID_ADDRESS;
+
+  unsigned prot = 0;
+  if (permissions & lldb::ePermissionsReadable)
+    prot |= eMmapProtRead;
+  if (permissions & lldb::ePermissionsWritable)
+    prot |= eMmapProtWrite;
+  if (permissions & lldb::ePermissionsExecutable)
+    prot |= eMmapProtExec;
+
+  // TODO implement this directly in NativeProcessNetBSD
+  // (and lift to NativeProcessPOSIX if/when that class is
+  // refactored out).
+  if (InferiorCallMmap(this, addr, 0, size, prot,
+                       eMmapFlagsAnon | eMmapFlagsPrivate, -1, 0)) {
+    m_addr_to_mmap_size[addr] = size;
+    return Error();
+  } else {
+    addr = LLDB_INVALID_ADDRESS;
+    return Error("unable to allocate %" PRIu64
+                 " bytes of memory with permissions %s",
+                 size, GetPermissionsAsCString(permissions));
+  }
+#endif
+}
+
+Error NativeProcessNetBSD::DeallocateMemory(lldb::addr_t addr) {
+  // FIXME see comments in AllocateMemory - required lower-level
+  // bits not in place yet (ThreadPlans)
+  return Error("not implemented");
+}
+
+lldb::addr_t NativeProcessNetBSD::GetSharedLibraryInfoAddress() {
+  // punt on this for now
+  return LLDB_INVALID_ADDRESS;
+}
+
+size_t NativeProcessNetBSD::UpdateThreads() {
+  // The NativeProcessNetBSD monitoring threads are always up to date
+  // with respect to thread state and they keep the thread list
+  // populated properly. All this method needs to do is return the
+  // thread count.
+  return m_threads.size();
+}
+
+bool NativeProcessNetBSD::GetArchitecture(ArchSpec &arch) const {
+  arch = m_arch;
+  return true;
+}
+
+Error NativeProcessNetBSD::SetBreakpoint(lldb::addr_t addr, uint32_t size,
+                                        bool hardware) {
+  if (hardware)
+    return Error("NativeProcessNetBSD does not support hardware breakpoints");
+  else
+    return SetSoftwareBreakpoint(addr, size);
+}
+
+Error NativeProcessNetBSD::GetSoftwareBreakpointTrapOpcode(
+    size_t trap_opcode_size_hint, size_t &actual_opcode_size,
+    const uint8_t *&trap_opcode_bytes) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::ReadMemory(lldb::addr_t addr, void *buf, size_t size,
+                                     size_t &bytes_read) {
+  unsigned char *dst = static_cast<unsigned char *>(buf);
+  struct ptrace_io_desc io;
+
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_ALL));
+  if (log)
+    ProcessPOSIXLog::IncNestLevel();
+  if (log && ProcessPOSIXLog::AtTopNestLevel() &&
+      log->GetMask().Test(POSIX_LOG_MEMORY))
+    log->Printf("NativeProcessNetBSD::%s(%p, %p, %zd, _)", __FUNCTION__,
+                (void *)addr, buf, size);
+
+  bytes_read = 0;
+  io.piod_op = PIOD_READ_D;
+  io.piod_len = size;
+
+  do {
+    io.piod_offs = (void *)(addr + bytes_read);
+    io.piod_offs = dst + bytes_read;
+
+    Error error = NativeProcessNetBSD::PtraceWrapper(
+        PT_IO, GetID(), &io);
+    if (error.Fail()) {
+      if (log)
+        ProcessPOSIXLog::DecNestLevel();
+      return error;
+    }
+
+    bytes_read = io.piod_len;
+    io.piod_len = size - bytes_read;
+  } while(bytes_read < size);
+
+  if (log)
+    ProcessPOSIXLog::DecNestLevel();
+  return Error();
+}
+
+Error NativeProcessNetBSD::ReadMemoryWithoutTrap(lldb::addr_t addr, void *buf,
+                                                size_t size,
+                                                size_t &bytes_read) {
+  Error error = ReadMemory(addr, buf, size, bytes_read);
+  if (error.Fail())
+    return error;
+  return m_breakpoint_list.RemoveTrapsFromBuffer(addr, buf, size);
+}
+
+Error NativeProcessNetBSD::WriteMemory(lldb::addr_t addr, const void *buf,
+                                      size_t size, size_t &bytes_written) {
+  const unsigned char *src = static_cast<const unsigned char *>(buf);
+  Error error;
+  struct ptrace_io_desc io;
+
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_ALL));
+  if (log)
+    ProcessPOSIXLog::IncNestLevel();
+  if (log && ProcessPOSIXLog::AtTopNestLevel() &&
+      log->GetMask().Test(POSIX_LOG_MEMORY))
+    log->Printf("NativeProcessNetBSD::%s(0x%" PRIx64 ", %p, %zu)", __FUNCTION__,
+                addr, buf, size);
+
+  bytes_written = 0;
+  io.piod_op = PIOD_WRITE_D;
+  io.piod_len = size;
+
+  do {
+    io.piod_offs = (void *)(src + bytes_written);
+    io.piod_offs = (void *)(addr + bytes_written);
+
+    Error error = NativeProcessNetBSD::PtraceWrapper(
+        PT_IO, GetID(), &io);
+    if (error.Fail()) {
+      if (log)
+        ProcessPOSIXLog::DecNestLevel();
+      return error;
+    }
+
+    bytes_written = io.piod_len;
+    io.piod_len = size - bytes_written;
+  } while(bytes_written < size);
+
+  if (log)
+    ProcessPOSIXLog::DecNestLevel();
+  return error;
+}
+
+bool NativeProcessNetBSD::HasThreadNoLock(lldb::tid_t thread_id) {
+  for (auto thread_sp : m_threads) {
+    assert(thread_sp && "thread list should not contain NULL threads");
+    if (thread_sp->GetID() == thread_id) {
+      // We have this thread.
+      return true;
+    }
+  }
+
+  // We don't have this thread.
+  return false;
+}
+
+NativeThreadNetBSDSP NativeProcessNetBSD::AddThread(lldb::tid_t thread_id) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
+
+  if (log) {
+    log->Printf("NativeProcessNetBSD::%s pid %" PRIu64
+                " adding thread with tid %" PRIu64,
+                __FUNCTION__, GetID(), thread_id);
+  }
+
+  assert(!HasThreadNoLock(thread_id) &&
+         "attempted to add a thread by id that already exists");
+
+  // If this is the first thread, save it as the current thread
+  if (m_threads.empty())
+    SetCurrentThreadID(thread_id);
+
+  auto thread_sp = std::make_shared<NativeThreadNetBSD>(this, thread_id);
+  m_threads.push_back(thread_sp);
+  return thread_sp;
+}
+
+Error NativeProcessNetBSD::GetLoadedModuleFileSpec(const char *module_path,
+                                                  FileSpec &file_spec) {
+  FileSpec module_file_spec(module_path, true);
+
+  bool found = false;
+  file_spec.Clear();
+
+  if (!found)
+    return Error("Module file (%s) not found in /proc/%" PRIu64 "/maps file!",
+                 module_file_spec.GetFilename().AsCString(), GetID());
+
+  return Error();
+}
+
+Error NativeProcessNetBSD::GetFileLoadAddress(const llvm::StringRef &file_name,
+                                             lldb::addr_t &load_addr) {
+  load_addr = LLDB_INVALID_ADDRESS;
+  return Error();
+}
+
+NativeThreadNetBSDSP NativeProcessNetBSD::GetThreadByID(lldb::tid_t tid) {
+  return std::static_pointer_cast<NativeThreadNetBSD>(
+      NativeProcessProtocol::GetThreadByID(tid));
+}
+
+//===----------------------------------------------------------------------===//
+
+void NativeProcessNetBSD::SigchldHandler() {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
+  // Process all pending waitpid notifications.
+  int status;
+  ::pid_t wait_pid = waitpid(WAIT_ANY, &status, WALLSIG | WNOHANG);
+
+  if (wait_pid == 0)
+    return; // We are done.
+
+  if (wait_pid == -1) {
+    if (errno == EINTR)
+      return;
+
+    Error error(errno, eErrorTypePOSIX);
+    if (log)
+      log->Printf("NativeProcessNetBSD::%s waitpid (WAIT_ANY, &status, "
+                  "WALLSIG | WNOHANG) failed: %s", __FUNCTION__,
+                  error.AsCString());
+  }
+
+  bool exited = false;
+  int signal = 0;
+  int exit_status = 0;
+  const char *status_cstr = nullptr;
+  if (WIFSTOPPED(status)) {
+    signal = WSTOPSIG(status);
+    status_cstr = "STOPPED";
+  } else if (WIFEXITED(status)) {
+    exit_status = WEXITSTATUS(status);
+    status_cstr = "EXITED";
+    exited = true;
+  } else if (WIFSIGNALED(status)) {
+    signal = WTERMSIG(status);
+    status_cstr = "SIGNALED";
+    if (wait_pid == static_cast<::pid_t>(GetID())) {
+      exited = true;
+      exit_status = -1;
+    }
+  } else
+    status_cstr = "(\?\?\?)";
+
+  if (log)
+    log->Printf("NativeProcessNetBSD::%s: waitpid (WAIT_ANY, &status, "
+                "WALLSIG | WNOHANG) => pid = %" PRIi32
+                ", status = 0x%8.8x (%s), signal = %i, exit_state = %i",
+                __FUNCTION__, wait_pid, status, status_cstr, signal,
+                exit_status);
+
+  MonitorCallback(wait_pid, exited, signal, exit_status);
+}
+
+// Wrapper for ptrace to catch errors and log calls.
+// Note that ptrace sets errno on error because -1 can be a valid result (i.e.
+// for PT_READ*)
+Error NativeProcessNetBSD::PtraceWrapper(int req, lldb::pid_t pid, void *addr,
+                                        int data, int *result) {
+  Error error;
+  int ret;
+
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PTRACE));
+
+  PtraceDisplayBytes(req, addr, data);
+
+  errno = 0;
+  ret = ptrace(req, static_cast<::pid_t>(pid), addr, data);
+
+  if (ret == -1)
+    error.SetErrorToErrno();
+
+  if (result)
+    *result = ret;
+
+  if (log)
+    log->Printf("ptrace(%d, %d, %p, %d, %d)=%lX", req, pid, addr,
+                data, ret);
+
+  if (log && error.GetError() != 0) {
+    const char *str;
+    switch (error.GetError()) {
+    case ESRCH:
+      str = "ESRCH";
+      break;
+    case EINVAL:
+      str = "EINVAL";
+      break;
+    case EBUSY:
+      str = "EBUSY";
+      break;
+    case EPERM:
+      str = "EPERM";
+      break;
+    default:
+      str = error.AsCString();
+    }
+    log->Printf("ptrace() failed; errno=%d (%s)", error.GetError(), str);
+  }
+
+  return error;
+}
