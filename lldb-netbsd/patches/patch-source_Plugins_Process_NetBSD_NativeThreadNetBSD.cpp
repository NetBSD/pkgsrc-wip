$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp.orig	2017-03-29 00:14:15.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp
@@ -56,6 +56,18 @@ void NativeThreadNetBSD::SetStoppedByBre
   m_stop_info.details.signal.signo = SIGTRAP;
 }
 
+void NativeThreadNetBSD::SetStoppedByTrace() {
+  SetStopped();
+  m_stop_info.reason = StopReason::eStopReasonTrace;
+  m_stop_info.details.signal.signo = SIGTRAP;
+}
+
+void NativeThreadNetBSD::SetStoppedByExec() {
+  SetStopped();
+  m_stop_info.reason = StopReason::eStopReasonExec;
+  m_stop_info.details.signal.signo = SIGTRAP;
+}
+
 void NativeThreadNetBSD::SetStopped() {
   const StateType new_state = StateType::eStateStopped;
   m_state = new_state;
@@ -67,6 +79,11 @@ void NativeThreadNetBSD::SetRunning() {
   m_stop_info.reason = StopReason::eStopReasonNone;
 }
 
+void NativeThreadNetBSD::SetStepping() {
+  m_state = StateType::eStateStepping;
+  m_stop_info.reason = StopReason::eStopReasonNone;
+}
+
 std::string NativeThreadNetBSD::GetName() { return std::string(""); }
 
 lldb::StateType NativeThreadNetBSD::GetState() { return m_state; }
