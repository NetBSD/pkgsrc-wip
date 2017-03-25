$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp.orig	2017-03-21 17:54:57.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp
@@ -12,6 +12,11 @@
 
 #include "NativeProcessNetBSD.h"
 
+#include "Plugins/Process/POSIX/CrashReason.h"
+#include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
+#include "lldb/Core/RegisterValue.h"
+#include "lldb/Core/State.h"
+
 using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::process_netbsd;
@@ -19,3 +24,44 @@ using namespace lldb_private::process_ne
 NativeThreadNetBSD::NativeThreadNetBSD(NativeProcessNetBSD *process,
                                        lldb::tid_t tid)
     : NativeThreadProtocol(process, tid) {}
+
+void NativeThreadNetBSD::SetStoppedBySignal(uint32_t signo,
+                                            const siginfo_t *info) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
+  if (log)
+    log->Printf("NativeThreadNetBSD::%s called with signal 0x%02" PRIx32,
+                __FUNCTION__, signo);
+
+  SetStopped();
+
+  m_stop_info.reason = StopReason::eStopReasonSignal;
+  m_stop_info.details.signal.signo = signo;
+
+  m_stop_description.clear();
+  if (info) {
+    switch (signo) {
+    case SIGSEGV:
+    case SIGBUS:
+    case SIGFPE:
+    case SIGILL:
+      const auto reason = GetCrashReason(*info);
+      m_stop_description = GetCrashReasonString(reason, *info);
+      break;
+    }
+  }
+}
+
+void NativeThreadNetBSD::SetStoppedByBreakpoint() {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
+  if (log)
+    log->Printf("NativeThreadNetBSD::%s()", __FUNCTION__);
+  SetStopped();
+  m_stop_info.reason = StopReason::eStopReasonBreakpoint;
+  m_stop_info.details.signal.signo = SIGTRAP;
+}
+
+void NativeThreadNetBSD::SetStopped() {
+  const StateType new_state = StateType::eStateStopped;
+  m_state = new_state;
+  m_stop_description.clear();
+}
