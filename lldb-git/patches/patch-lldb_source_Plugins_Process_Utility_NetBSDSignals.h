$NetBSD$

--- lldb/source/Plugins/Process/Utility/NetBSDSignals.h.orig	2015-12-13 05:10:49.000000000 +0000
+++ lldb/source/Plugins/Process/Utility/NetBSDSignals.h
@@ -0,0 +1,31 @@
+//===-- NetBSDSignals.h ----------------------------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#ifndef liblldb_NetBSDSignals_H_
+#define liblldb_NetBSDSignals_H_
+
+// Project includes
+#include "lldb/Target/UnixSignals.h"
+
+namespace lldb_private {
+
+/// NetBSD specific set of Unix signals.
+class NetBSDSignals : public UnixSignals
+{
+public:
+    NetBSDSignals();
+
+private:
+    void
+    Reset() override;
+};
+
+} // namespace lldb_private
+
+#endif // liblldb_NetBSDSignals_H_
