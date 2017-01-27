$NetBSD$

--- source/Core/Debugger.cpp.orig	2016-12-17 10:30:30.000000000 +0000
+++ source/Core/Debugger.cpp
@@ -61,8 +61,11 @@
 #include "lldb/Utility/AnsiTerminal.h"
 #include "lldb/lldb-private.h"
 
+#include "llvm/Support/Threading.h"
+
 using namespace lldb;
 using namespace lldb_private;
+using namespace llvm;
 
 static lldb::user_id_t g_unique_id = 1;
 static size_t g_debugger_event_thread_stack_bytes = 8 * 1024 * 1024;
@@ -710,7 +713,7 @@ Debugger::Debugger(lldb::LogOutputCallba
       m_input_reader_stack(), m_instance_name(), m_loaded_plugins(),
       m_event_handler_thread(), m_io_handler_thread(),
       m_sync_broadcaster(nullptr, "lldb.debugger.sync"),
-      m_forward_listener_sp(), m_clear_once() {
+      m_forward_listener_sp() {
   char instance_cstr[256];
   snprintf(instance_cstr, sizeof(instance_cstr), "debugger_%d", (int)GetID());
   m_instance_name.SetCString(instance_cstr);
@@ -762,7 +765,8 @@ void Debugger::Clear() {
   //     static void Debugger::Destroy(lldb::DebuggerSP &debugger_sp);
   //     static void Debugger::Terminate();
   //----------------------------------------------------------------------
-  std::call_once(m_clear_once, [this]() {
+  LLVM_DEFINE_ONCE_FLAG(m_clear_once);
+  llvm::call_once(m_clear_once, [this]() {
     ClearIOHandlers();
     StopIOHandlerThread();
     StopEventHandlerThread();
