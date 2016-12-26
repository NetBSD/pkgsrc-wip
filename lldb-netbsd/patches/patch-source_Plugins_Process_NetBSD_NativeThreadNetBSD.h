$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.h.orig	2016-12-26 05:32:46.186458822 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.h
@@ -0,0 +1,79 @@
+//===-- NativeThreadNetBSD.h ----------------------------------- -*- C++ -*-===//
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
+#include "lldb/lldb-private-forward.h"
+
+#include <sched.h>
+
+#include <map>
+#include <memory>
+#include <string>
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
+
+  // ---------------------------------------------------------------------
+  // NativeThreadProtocol Interface
+  // ---------------------------------------------------------------------
+  std::string GetName() override;
+
+  lldb::StateType GetState() override;
+
+  bool GetStopReason(ThreadStopInfo &stop_info,
+                     std::string &description) override;
+
+  NativeRegisterContextSP GetRegisterContext() override;
+
+  Error SetWatchpoint(lldb::addr_t addr, size_t size, uint32_t watch_flags,
+                      bool hardware) override;
+
+  Error RemoveWatchpoint(lldb::addr_t addr) override;
+
+private:
+  // ---------------------------------------------------------------------
+  // Interface for friend classes
+  // ---------------------------------------------------------------------
+
+  /// Single steps the thread.  If @p signo is anything but
+  /// LLDB_INVALID_SIGNAL_NUMBER, deliver that signal to the thread.
+  Error SingleStep(uint32_t signo);
+
+  void SetStoppedBySignal(uint32_t signo, const siginfo_t *info = nullptr);
+
+  // ---------------------------------------------------------------------
+  // Private interface
+  // ---------------------------------------------------------------------
+  NativeProcessNetBSD &GetProcess();
+
+  // ---------------------------------------------------------------------
+  // Member Variables
+  // ---------------------------------------------------------------------
+  lldb::StateType m_state;
+  ThreadStopInfo m_stop_info;
+  NativeRegisterContextSP m_reg_context_sp;
+  std::string m_stop_description;
+};
+
+typedef std::shared_ptr<NativeThreadNetBSD> NativeThreadNetBSDSP;
+} // namespace process_netbsd
+} // namespace lldb_private
+
+#endif // #ifndef liblldb_NativeThreadNetBSD_H_
