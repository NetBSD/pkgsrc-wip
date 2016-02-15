$NetBSD$

--- src/debug/di/breakpoint.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/di/breakpoint.cpp
@@ -190,7 +190,7 @@ HRESULT CordbFunctionBreakpoint::Activat
     pProcess->ClearPatchTable(); // if we add something, then the right side 
                                 // view of the patch table is no longer valid
 
-    DebuggerIPCEvent * pEvent = (DebuggerIPCEvent *) _alloca(CorDBIPC_BUFFER_SIZE);
+    DebuggerIPCEvent * pEvent = (DebuggerIPCEvent *) Alloca(CorDBIPC_BUFFER_SIZE);
 
     CordbAppDomain * pAppDomain = GetAppDomain();
     _ASSERTE (pAppDomain != NULL);
@@ -507,7 +507,7 @@ HRESULT CordbStepper::StepRange(BOOL fSt
     // Build step event
     //
 
-    DebuggerIPCEvent * pEvent = reinterpret_cast<DebuggerIPCEvent *>(_alloca(CorDBIPC_BUFFER_SIZE));
+    DebuggerIPCEvent * pEvent = reinterpret_cast<DebuggerIPCEvent *>(Alloca(CorDBIPC_BUFFER_SIZE));
 
     pProcess->InitIPCEvent(pEvent, DB_IPCE_STEP, true, GetAppDomain()->GetADToken());
 
@@ -674,7 +674,7 @@ HRESULT CordbStepper::StepOut()
     // Build step event
     //
 
-    DebuggerIPCEvent * pEvent = (DebuggerIPCEvent *) _alloca(CorDBIPC_BUFFER_SIZE);
+    DebuggerIPCEvent * pEvent = (DebuggerIPCEvent *) Alloca(CorDBIPC_BUFFER_SIZE);
 
     pProcess->InitIPCEvent(pEvent, DB_IPCE_STEP_OUT, true, GetAppDomain()->GetADToken());
 
