$NetBSD$

--- source/Host/netbsd/ProcessLauncherNetBSD.cpp.orig	2016-12-19 03:03:08.647656376 +0000
+++ source/Host/netbsd/ProcessLauncherNetBSD.cpp
@@ -0,0 +1,170 @@
+//===-- ProcessLauncherNetBSD.cpp --------------------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#include "lldb/Host/netbsd/ProcessLauncherNetBSD.h"
+#include "lldb/Core/Log.h"
+#include "lldb/Host/FileSpec.h"
+#include "lldb/Host/Host.h"
+#include "lldb/Host/HostProcess.h"
+#include "lldb/Host/Pipe.h"
+#include "lldb/Target/ProcessLaunchInfo.h"
+
+#include <limits.h>
+#include <sys/ptrace.h>
+#include <sys/wait.h>
+
+#include <sstream>
+
+using namespace lldb;
+using namespace lldb_private;
+
+static void LLVM_ATTRIBUTE_NORETURN ExitWithError(int error_fd,
+                                                  const char *operation) {
+  std::ostringstream os;
+  os << operation << " failed: " << strerror(errno);
+  write(error_fd, os.str().data(), os.str().size());
+  close(error_fd);
+  _exit(1);
+}
+
+static void DupDescriptor(int error_fd, const FileSpec &file_spec, int fd,
+                          int flags) {
+  int target_fd = ::open(file_spec.GetCString(), flags, 0666);
+
+  if (target_fd == -1)
+    ExitWithError(error_fd, "DupDescriptor-open");
+
+  if (target_fd == fd)
+    return;
+
+  if (::dup2(target_fd, fd) == -1)
+    ExitWithError(error_fd, "DupDescriptor-dup2");
+
+  ::close(target_fd);
+  return;
+}
+
+static void LLVM_ATTRIBUTE_NORETURN ChildFunc(int error_fd,
+                                              const ProcessLaunchInfo &info) {
+  // First, make sure we disable all logging. If we are logging to stdout, our
+  // logs can be
+  // mistaken for inferior output.
+  Log::DisableAllLogChannels(nullptr);
+
+  // Do not inherit setgid powers.
+  if (setgid(getgid()) != 0)
+    ExitWithError(error_fd, "setgid");
+
+  if (info.GetFlags().Test(eLaunchFlagLaunchInSeparateProcessGroup)) {
+    if (setpgid(0, 0) != 0)
+      ExitWithError(error_fd, "setpgid");
+  }
+
+  for (size_t i = 0; i < info.GetNumFileActions(); ++i) {
+    const FileAction &action = *info.GetFileActionAtIndex(i);
+    switch (action.GetAction()) {
+    case FileAction::eFileActionClose:
+      if (close(action.GetFD()) != 0)
+        ExitWithError(error_fd, "close");
+      break;
+    case FileAction::eFileActionDuplicate:
+      if (dup2(action.GetFD(), action.GetActionArgument()) == -1)
+        ExitWithError(error_fd, "dup2");
+      break;
+    case FileAction::eFileActionOpen:
+      DupDescriptor(error_fd, action.GetFileSpec(), action.GetFD(),
+                    action.GetActionArgument());
+      break;
+    case FileAction::eFileActionNone:
+      break;
+    }
+  }
+
+  const char **argv = info.GetArguments().GetConstArgumentVector();
+
+  // Change working directory
+  if (info.GetWorkingDirectory() &&
+      0 != ::chdir(info.GetWorkingDirectory().GetCString()))
+    ExitWithError(error_fd, "chdir");
+
+  Args env = info.GetEnvironmentEntries();
+  const char **envp = env.GetConstArgumentVector();
+
+  // Clear the signal mask to prevent the child from being affected by
+  // any masking done by the parent.
+  sigset_t set;
+  if (sigemptyset(&set) != 0 ||
+      sigprocmask(SIG_SETMASK, &set, nullptr) != 0)
+    ExitWithError(error_fd, "pthread_sigmask");
+
+  if (info.GetFlags().Test(eLaunchFlagDebug)) {
+    // HACK:
+    // Close everything besides stdin, stdout, and stderr that has no file
+    // action to avoid leaking. Only do this when debugging, as elsewhere we
+    // actually rely on
+    // passing open descriptors to child processes.
+    for (int fd = 3; fd < sysconf(_SC_OPEN_MAX); ++fd)
+      if (!info.GetFileActionForFD(fd) && fd != error_fd)
+        close(fd);
+
+    // Start tracing this child that is about to exec.
+    if (ptrace(PTRACE_TRACEME, 0, nullptr, nullptr) == -1)
+      ExitWithError(error_fd, "ptrace");
+  }
+
+  // Execute.  We should never return...
+  execve(argv[0], const_cast<char *const *>(argv),
+         const_cast<char *const *>(envp));
+
+  // ...unless exec fails.  In which case we definitely need to end the child
+  // here.
+  ExitWithError(error_fd, "execve");
+}
+
+HostProcess
+ProcessLauncherNetBSD::LaunchProcess(const ProcessLaunchInfo &launch_info,
+                                    Error &error) {
+  char exe_path[PATH_MAX];
+  launch_info.GetExecutableFile().GetPath(exe_path, sizeof(exe_path));
+
+  // A pipe used by the child process to report errors.
+  PipePosix pipe;
+  const bool child_processes_inherit = false;
+  error = pipe.CreateNew(child_processes_inherit);
+  if (error.Fail())
+    return HostProcess();
+
+  ::pid_t pid = ::fork();
+  if (pid == -1) {
+    // Fork failed
+    error.SetErrorStringWithFormat("Fork failed with error message: %s",
+                                   strerror(errno));
+    return HostProcess(LLDB_INVALID_PROCESS_ID);
+  }
+  if (pid == 0) {
+    // child process
+    pipe.CloseReadFileDescriptor();
+    ChildFunc(pipe.ReleaseWriteFileDescriptor(), launch_info);
+  }
+
+  // parent process
+
+  pipe.CloseWriteFileDescriptor();
+  char buf[1000];
+  int r = read(pipe.GetReadFileDescriptor(), buf, sizeof buf);
+
+  if (r == 0)
+    return HostProcess(pid); // No error. We're done.
+
+  error.SetErrorString(buf);
+
+  waitpid(pid, nullptr, 0);
+
+  return HostProcess();
+}
