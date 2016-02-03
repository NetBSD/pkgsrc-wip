$NetBSD$

--- src/debug/ee/debuggermodule.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/ee/debuggermodule.cpp
@@ -103,7 +103,6 @@ void DebuggerModule::SetCanChangeJitFlag
 
 #ifndef DACCESS_COMPILE
 
-
 DebuggerModuleTable::DebuggerModuleTable() : CHashTableAndData<CNewZeroData>(101)
 {
     WRAPPER_NO_CONTRACT;
@@ -440,5 +439,3 @@ DebuggerModule *DebuggerModuleTable::Get
     else
         return entry->module;
 }
-
-
