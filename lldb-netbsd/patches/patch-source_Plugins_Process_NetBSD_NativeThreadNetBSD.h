$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.h.orig	2017-03-29 00:14:15.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.h
@@ -51,8 +51,11 @@ private:
 
   void SetStoppedBySignal(uint32_t signo, const siginfo_t *info = nullptr);
   void SetStoppedByBreakpoint();
+  void SetStoppedByTrace();
+  void SetStoppedByExec();
   void SetStopped();
   void SetRunning();
+  void SetStepping();
 
   // ---------------------------------------------------------------------
   // Member Variables
