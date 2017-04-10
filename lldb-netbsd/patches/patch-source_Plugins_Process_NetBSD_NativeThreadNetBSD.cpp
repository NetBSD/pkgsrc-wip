$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp
@@ -16,6 +16,9 @@
 #include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
 #include "lldb/Core/RegisterValue.h"
 #include "lldb/Core/State.h"
+#include "lldb/Utility/LLDBAssert.h"
+
+#include <sstream>
 
 using namespace lldb;
 using namespace lldb_private;
@@ -68,6 +71,23 @@ void NativeThreadNetBSD::SetStoppedByExe
   m_stop_info.details.signal.signo = SIGTRAP;
 }
 
+void NativeThreadNetBSD::SetStoppedByWatchpoint(uint32_t wp_index) {
+  SetStopped();
+
+  lldbassert(wp_index != LLDB_INVALID_INDEX32 && "wp_index cannot be invalid");
+
+  std::ostringstream ostr;
+  ostr << GetRegisterContext()->GetWatchpointAddress(wp_index) << " ";
+  ostr << wp_index;
+
+  ostr << " " << GetRegisterContext()->GetWatchpointHitAddress(wp_index);
+  
+  m_stop_description = ostr.str();
+  
+  m_stop_info.reason = StopReason::eStopReasonWatchpoint;
+  m_stop_info.details.signal.signo = SIGTRAP;
+}
+
 void NativeThreadNetBSD::SetStopped() {
   const StateType new_state = StateType::eStateStopped;
   m_state = new_state;
@@ -142,18 +162,61 @@ NativeRegisterContextSP NativeThreadNetB
 
 Error NativeThreadNetBSD::SetWatchpoint(lldb::addr_t addr, size_t size,
                                         uint32_t watch_flags, bool hardware) {
-  return Error("Unimplemented");
+  if (!hardware)
+    return Error("not implemented");
+  if (m_state == eStateLaunching)
+    return Error();
+  Error error = RemoveWatchpoint(addr);
+  if (error.Fail())
+    return error;
+  NativeRegisterContextSP reg_ctx = GetRegisterContext();
+  uint32_t wp_index = reg_ctx->SetHardwareWatchpoint(addr, size, watch_flags);
+  if (wp_index == LLDB_INVALID_INDEX32)
+    return Error("Setting hardware watchpoint failed.");
+  m_watchpoint_index_map.insert({addr, wp_index});
+  return Error();
 }
 
 Error NativeThreadNetBSD::RemoveWatchpoint(lldb::addr_t addr) {
-  return Error("Unimplemented");
+  auto wp = m_watchpoint_index_map.find(addr);
+  if (wp == m_watchpoint_index_map.end())
+    return Error();
+  uint32_t wp_index = wp->second;
+  m_watchpoint_index_map.erase(wp);
+  if (GetRegisterContext()->ClearHardwareWatchpoint(wp_index))
+    return Error();
+  return Error("Clearing hardware watchpoint failed.");
 }
 
 Error NativeThreadNetBSD::SetHardwareBreakpoint(lldb::addr_t addr,
                                                 size_t size) {
-  return Error("Unimplemented");
+  if (m_state == eStateLaunching)
+    return Error();
+
+  Error error = RemoveHardwareBreakpoint(addr);
+  if (error.Fail())
+    return error;
+
+  NativeRegisterContextSP reg_ctx = GetRegisterContext();
+  uint32_t bp_index = reg_ctx->SetHardwareBreakpoint(addr, size);
+
+  if (bp_index == LLDB_INVALID_INDEX32)
+    return Error("Setting hardware breakpoint failed.");
+
+  m_hw_break_index_map.insert({addr, bp_index});
+  return Error();
 }
 
 Error NativeThreadNetBSD::RemoveHardwareBreakpoint(lldb::addr_t addr) {
-  return Error("Unimplemented");
+  auto bp = m_hw_break_index_map.find(addr);
+  if (bp == m_hw_break_index_map.end())
+    return Error();
+
+  uint32_t bp_index = bp->second;
+  if (GetRegisterContext()->ClearHardwareBreakpoint(bp_index)) {
+    m_hw_break_index_map.erase(bp);
+    return Error();
+  }
+
+  return Error("Clearing hardware breakpoint failed.");
 }
