$NetBSD$

--- src/debug/di/process.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/di/process.cpp
@@ -1970,7 +1970,7 @@ void SendAttachProcessWorkItem::Do()
     // This is being processed on the RCET, where it's safe to take the Stop-Go lock.
     RSLockHolder ch(this->GetProcess()->GetStopGoLock());
 
-    DebuggerIPCEvent *event = (DebuggerIPCEvent*) _alloca(CorDBIPC_BUFFER_SIZE);
+    DebuggerIPCEvent *event = (DebuggerIPCEvent*) Alloca(CorDBIPC_BUFFER_SIZE);
     
     // This just acts like an async-break, which will kick off things.
     // This will not induce any faked attach events from the VM (like it did in V2).
@@ -2511,7 +2511,7 @@ COM_METHOD CordbProcess::InvokePauseCall
     
     EX_TRY
     {
-        DebuggerIPCEvent * pIPCEvent = (DebuggerIPCEvent *) _alloca(CorDBIPC_BUFFER_SIZE);
+        DebuggerIPCEvent * pIPCEvent = (DebuggerIPCEvent *) Alloca(CorDBIPC_BUFFER_SIZE);
         InitIPCEvent(pIPCEvent, DB_IPCE_NETCF_HOST_CONTROL_PAUSE, true, VMPTR_AppDomain::NullPtr());
 
         hr = m_cordb->SendIPCEvent(this, pIPCEvent, CorDBIPC_BUFFER_SIZE);
@@ -2530,7 +2530,7 @@ COM_METHOD CordbProcess::InvokeResumeCal
     
     EX_TRY
     {
-        DebuggerIPCEvent * pIPCEvent = (DebuggerIPCEvent *) _alloca(CorDBIPC_BUFFER_SIZE);
+        DebuggerIPCEvent * pIPCEvent = (DebuggerIPCEvent *) Alloca(CorDBIPC_BUFFER_SIZE);
         InitIPCEvent(pIPCEvent, DB_IPCE_NETCF_HOST_CONTROL_RESUME, true, VMPTR_AppDomain::NullPtr());
 
         hr = m_cordb->SendIPCEvent(this, pIPCEvent, CorDBIPC_BUFFER_SIZE);
@@ -3090,7 +3090,7 @@ void CordbProcess::DetachShim()
         }
 
         // Go ahead and detach from the entire process now. This is like sending a "Continue".
-        DebuggerIPCEvent * pIPCEvent = (DebuggerIPCEvent *) _alloca(CorDBIPC_BUFFER_SIZE);
+        DebuggerIPCEvent * pIPCEvent = (DebuggerIPCEvent *) Alloca(CorDBIPC_BUFFER_SIZE);
         InitIPCEvent(pIPCEvent, DB_IPCE_DETACH_FROM_PROCESS, true, VMPTR_AppDomain::NullPtr());
 
         hr = m_cordb->SendIPCEvent(this, pIPCEvent, CorDBIPC_BUFFER_SIZE);
@@ -3502,7 +3502,7 @@ HRESULT CordbProcess::StopInternal(DWORD
     }
 
     // Send the async break event to the RC.
-    event = (DebuggerIPCEvent*) _alloca(CorDBIPC_BUFFER_SIZE);
+    event = (DebuggerIPCEvent*) Alloca(CorDBIPC_BUFFER_SIZE);
     InitIPCEvent(event, DB_IPCE_ASYNC_BREAK, false, pAppDomainToken);
 
     STRESS_LOG1(LF_CORDB, LL_INFO1000, "CP::S: sending async stop to appd 0x%x.\n", VmPtrToCookie(pAppDomainToken));
@@ -4115,7 +4115,7 @@ HRESULT CordbProcess::ContinueInternal(B
         STRESS_LOG2(LF_CORDB, LL_INFO1000, "Continue flags:special=%d, dowin32=%d\n", m_specialDeferment, fDoWin32Continue);
 #endif
         // Send to the RC to continue the process.
-        DebuggerIPCEvent * pEvent = (DebuggerIPCEvent *) _alloca(CorDBIPC_BUFFER_SIZE);
+        DebuggerIPCEvent * pEvent = (DebuggerIPCEvent *) Alloca(CorDBIPC_BUFFER_SIZE);
 
         InitIPCEvent(pEvent, DB_IPCE_CONTINUE, false, pAppDomainToken);
 
@@ -8404,7 +8404,7 @@ HRESULT CordbProcess::StartSyncFromWin32
             LOG((LF_CORDB, LL_INFO1000, "[%x] CP::SSFW32S: internal continue returned\n", GetCurrentThreadId()));
 
             // Send an async break to the left side now that its running.
-            DebuggerIPCEvent * pEvent = (DebuggerIPCEvent *) _alloca(CorDBIPC_BUFFER_SIZE);
+            DebuggerIPCEvent * pEvent = (DebuggerIPCEvent *) Alloca(CorDBIPC_BUFFER_SIZE);
             InitIPCEvent(pEvent, DB_IPCE_ASYNC_BREAK, false, VMPTR_AppDomain::NullPtr());
 
             LOG((LF_CORDB, LL_INFO1000, "[%x] CP::SSFW32S: sending async stop\n", GetCurrentThreadId()));
@@ -8616,7 +8616,7 @@ HRESULT CordbProcess::EnableLogMessages(
     ATT_REQUIRE_STOPPED_MAY_FAIL(this);
     HRESULT hr = S_OK;
 
-    DebuggerIPCEvent *event = (DebuggerIPCEvent*) _alloca(CorDBIPC_BUFFER_SIZE);
+    DebuggerIPCEvent *event = (DebuggerIPCEvent*) Alloca(CorDBIPC_BUFFER_SIZE);
     InitIPCEvent(event, DB_IPCE_ENABLE_LOG_MESSAGES, false, VMPTR_AppDomain::NullPtr());
     event->LogSwitchSettingMessage.iLevel = (int)fOnOff;
 
@@ -8642,7 +8642,7 @@ COM_METHOD CordbProcess::ModifyLogSwitch
 
     _ASSERTE (pLogSwitchName != NULL);
 
-    DebuggerIPCEvent *event = (DebuggerIPCEvent*) _alloca(CorDBIPC_BUFFER_SIZE);
+    DebuggerIPCEvent *event = (DebuggerIPCEvent*) Alloca(CorDBIPC_BUFFER_SIZE);
     InitIPCEvent(event, DB_IPCE_MODIFY_LOGSWITCH, false, VMPTR_AppDomain::NullPtr());
     event->LogSwitchSettingMessage.iLevel = lLevel;
     event->LogSwitchSettingMessage.szSwitchName.SetStringTruncate(pLogSwitchName);
