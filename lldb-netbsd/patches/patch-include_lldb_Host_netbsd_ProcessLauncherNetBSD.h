$NetBSD$

--- include/lldb/Host/netbsd/ProcessLauncherNetBSD.h.orig	2017-01-31 18:01:27.231199052 +0000
+++ include/lldb/Host/netbsd/ProcessLauncherNetBSD.h
@@ -0,0 +1,25 @@
+//===-- ProcessLauncherNetBSD.h --------------------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#ifndef lldb_Host_netbsd_ProcessLauncherNetBSD_h_
+#define lldb_Host_netbsd_ProcessLauncherNetBSD_h_
+
+#include "lldb/Host/ProcessLauncher.h"
+
+namespace lldb_private {
+
+class ProcessLauncherNetBSD : public ProcessLauncher {
+public:
+  virtual HostProcess LaunchProcess(const ProcessLaunchInfo &launch_info,
+                                    Error &error);
+};
+
+} // end of namespace lldb_private
+
+#endif
