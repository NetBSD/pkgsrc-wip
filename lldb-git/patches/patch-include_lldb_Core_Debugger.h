$NetBSD$

--- include/lldb/Core/Debugger.h.orig	2016-12-14 14:10:24.000000000 +0000
+++ include/lldb/Core/Debugger.h
@@ -374,7 +374,6 @@ protected:
   HostThread m_io_handler_thread;
   Broadcaster m_sync_broadcaster;
   lldb::ListenerSP m_forward_listener_sp;
-  std::once_flag m_clear_once;
 
   //----------------------------------------------------------------------
   // Events for m_sync_broadcaster
