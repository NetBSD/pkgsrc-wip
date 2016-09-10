$NetBSD$

--- tools/lldb-mi/MIDriver.cpp.orig	2016-09-10 17:36:23.000000000 +0000
+++ tools/lldb-mi/MIDriver.cpp
@@ -509,7 +509,7 @@ bool CMIDriver::StartWorkerThreads() {
     const CMIUtilString errMsg = CMIUtilString::Format(
         MIRSRC(IDS_THREADMGR_ERR_THREAD_FAIL_CREATE),
         CMICmnThreadMgrStd::Instance().GetErrorDescription().c_str());
-    SetErrorDescriptionn(errMsg);
+    SetErrorDescriptionn(errMsg.c_str());
     return MIstatus::failure;
   }
 
