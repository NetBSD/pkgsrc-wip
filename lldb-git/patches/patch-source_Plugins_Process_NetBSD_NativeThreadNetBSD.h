$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.h.orig	2017-03-21 17:54:57.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.h
@@ -22,6 +22,45 @@ class NativeThreadNetBSD : public Native
 
 public:
   NativeThreadNetBSD(NativeProcessNetBSD *process, lldb::tid_t tid);
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
+  Error SetHardwareBreakpoint(lldb::addr_t addr, size_t size) override;
+
+  Error RemoveHardwareBreakpoint(lldb::addr_t addr) override;
+
+private:
+  // ---------------------------------------------------------------------
+  // Interface for friend classes
+  // ---------------------------------------------------------------------
+
+  void SetStoppedBySignal(uint32_t signo, const siginfo_t *info = nullptr);
+  void SetStoppedByBreakpoint();
+  void SetStopped();
+  void SetRunning();
+
+  // ---------------------------------------------------------------------
+  // Member Variables
+  // ---------------------------------------------------------------------
+  lldb::StateType m_state;
+  ThreadStopInfo m_stop_info;
+  NativeRegisterContextSP m_reg_context_sp;
+  std::string m_stop_description;
 };
 
 typedef std::shared_ptr<NativeThreadNetBSD> NativeThreadNetBSDSP;
