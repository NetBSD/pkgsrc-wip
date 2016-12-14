$NetBSD$

--- source/Plugins/Process/Linux/NativeThreadLinux.h.orig	2016-09-10 17:36:23.000000000 +0000
+++ source/Plugins/Process/Linux/NativeThreadLinux.h
@@ -107,7 +107,9 @@ private:
   std::string m_stop_description;
   using WatchpointIndexMap = std::map<lldb::addr_t, uint32_t>;
   WatchpointIndexMap m_watchpoint_index_map;
+#if !defined(__NetBSD__)
   cpu_set_t m_original_cpu_set; // For single-step workaround.
+#endif
 };
 
 typedef std::shared_ptr<NativeThreadLinux> NativeThreadLinuxSP;
