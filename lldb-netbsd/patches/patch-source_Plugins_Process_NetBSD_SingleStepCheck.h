$NetBSD$

--- source/Plugins/Process/NetBSD/SingleStepCheck.h.orig	2016-12-17 13:23:23.785649014 +0000
+++ source/Plugins/Process/NetBSD/SingleStepCheck.h
@@ -0,0 +1,40 @@
+//===-- SingleStepCheck.h ------------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#ifndef liblldb_SingleStepCheck_H_
+#define liblldb_SingleStepCheck_H_
+
+namespace lldb_private {
+namespace process_netbsd {
+
+namespace impl {
+extern bool SingleStepWorkaroundNeeded();
+}
+
+// arm64 netbsd had a bug which prevented single-stepping and watchpoints from
+// working on non-boot
+// cpus, due to them being incorrectly initialized after coming out of suspend.
+// This issue is
+// particularly affecting android M, which uses suspend ("doze mode") quite
+// aggressively. This
+// code detects that situation and makes single-stepping work by doing all the
+// step operations on
+// the boot cpu.
+//
+// The underlying issue has been fixed in android N and netbsd 4.4. This code can
+// be removed once
+// these systems become obsolete.
+inline bool SingleStepWorkaroundNeeded() {
+  static bool value = impl::SingleStepWorkaroundNeeded();
+  return value;
+}
+} // end namespace process_netbsd
+} // end namespace lldb_private
+
+#endif // #ifndef liblldb_SingleStepCheck_H_
