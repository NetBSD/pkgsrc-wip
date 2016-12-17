$NetBSD$

--- source/Plugins/Process/NetBSD/SingleStepCheck.cpp.orig	2016-12-17 13:23:23.785537353 +0000
+++ source/Plugins/Process/NetBSD/SingleStepCheck.cpp
@@ -0,0 +1,27 @@
+//===-- SingleStepCheck.cpp ----------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#include "SingleStepCheck.h"
+
+#include <sched.h>
+#include <signal.h>
+#include <sys/wait.h>
+#include <unistd.h>
+
+#include "NativeProcessNetBSD.h"
+
+#include "llvm/Support/Compiler.h"
+
+#include "lldb/Core/Error.h"
+#include "lldb/Core/Log.h"
+#include "lldb/Host/netbsd/Ptrace.h"
+
+using namespace lldb_private::process_netbsd;
+
+bool impl::SingleStepWorkaroundNeeded() { return false; }
