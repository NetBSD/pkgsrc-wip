$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.h.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.h
@@ -12,6 +12,9 @@
 
 #include "lldb/Host/common/NativeThreadProtocol.h"
 
+#include <map>
+#include <string>
+
 namespace lldb_private {
 namespace process_netbsd {
 
@@ -64,6 +67,9 @@ private:
   ThreadStopInfo m_stop_info;
   NativeRegisterContextSP m_reg_context_sp;
   std::string m_stop_description;
+  using WatchpointIndexMap = std::map<lldb::addr_t, uint32_t>;
+  WatchpointIndexMap m_watchpoint_index_map;
+  WatchpointIndexMap m_hw_break_index_map;
 };
 
 typedef std::shared_ptr<NativeThreadNetBSD> NativeThreadNetBSDSP;
