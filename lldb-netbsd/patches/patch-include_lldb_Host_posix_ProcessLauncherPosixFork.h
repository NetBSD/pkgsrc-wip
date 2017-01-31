$NetBSD$

--- include/lldb/Host/posix/ProcessLauncherPosixFork.h.orig	2017-01-31 22:15:25.384142043 +0000
+++ include/lldb/Host/posix/ProcessLauncherPosixFork.h
@@ -0,0 +1,25 @@
+//===-- ProcessLauncherPosixFork.h ------------------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#ifndef lldb_Host_posix_ProcessLauncherPosixFork_h_
+#define lldb_Host_posix_ProcessLauncherPosixFork_h_
+
+#include "lldb/Host/ProcessLauncher.h"
+
+namespace lldb_private {
+
+class ProcessLauncherPosixFork : public ProcessLauncher {
+public:
+  virtual HostProcess LaunchProcess(const ProcessLaunchInfo &launch_info,
+                                    Error &error);
+};
+
+} // end of namespace lldb_private
+
+#endif
