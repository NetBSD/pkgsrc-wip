$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.h.orig	2017-03-21 14:39:27.484287194 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.h
@@ -0,0 +1,31 @@
+//===-- NativeThreadNetBSD.h ---------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#ifndef liblldb_NativeThreadNetBSD_H_
+#define liblldb_NativeThreadNetBSD_H_
+
+#include "lldb/Host/common/NativeThreadProtocol.h"
+
+namespace lldb_private {
+namespace process_netbsd {
+
+class NativeProcessNetBSD;
+
+class NativeThreadNetBSD : public NativeThreadProtocol {
+  friend class NativeProcessNetBSD;
+
+public:
+  NativeThreadNetBSD(NativeProcessNetBSD *process, lldb::tid_t tid);
+};
+
+typedef std::shared_ptr<NativeThreadNetBSD> NativeThreadNetBSDSP;
+} // namespace process_netbsd
+} // namespace lldb_private
+
+#endif // #ifndef liblldb_NativeThreadNetBSD_H_
