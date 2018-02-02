$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2018-02-02 18:39:14.654259652 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -111,7 +111,6 @@ NativeProcessNetBSD::Factory::Launch(Pro
 
   for (const auto &thread : process_up->m_threads)
     static_cast<NativeThreadNetBSD &>(*thread).SetStoppedBySignal(SIGSTOP);
-  process_up->SetState(StateType::eStateStopped);
 
   return std::move(process_up);
 }
@@ -157,6 +156,11 @@ NativeProcessNetBSD::NativeProcessNetBSD
   m_sigchld_handle = mainloop.RegisterSignal(
       SIGCHLD, [this](MainLoopBase &) { SigchldHandler(); }, status);
   assert(m_sigchld_handle && status.Success());
+
+  SetState(StateType::eStateStopped, false);
+
+  // Proccess any signals we received before installing our handler
+  SigchldHandler();
 }
 
 // Handles all waitpid events from the inferior process.
