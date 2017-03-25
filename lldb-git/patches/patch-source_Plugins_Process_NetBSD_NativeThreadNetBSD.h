$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.h.orig	2017-03-21 17:54:57.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.h
@@ -22,6 +22,22 @@ class NativeThreadNetBSD : public Native
 
 public:
   NativeThreadNetBSD(NativeProcessNetBSD *process, lldb::tid_t tid);
+
+private:
+  // ---------------------------------------------------------------------
+  // Interface for friend classes
+  // ---------------------------------------------------------------------
+
+  void SetStoppedBySignal(uint32_t signo, const siginfo_t *info = nullptr);
+  void SetStoppedByBreakpoint();
+  void SetStopped();
+
+  // ---------------------------------------------------------------------
+  // Member Variables
+  // ---------------------------------------------------------------------
+  lldb::StateType m_state;
+  ThreadStopInfo m_stop_info;
+  std::string m_stop_description;
 };
 
 typedef std::shared_ptr<NativeThreadNetBSD> NativeThreadNetBSDSP;
