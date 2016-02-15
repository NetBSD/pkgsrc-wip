$NetBSD$

--- src/debug/di/module.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/di/module.cpp
@@ -2322,7 +2322,7 @@ HRESULT CordbModule::ApplyChangesInterna
         // We always copy over the whole buffer size which is bigger than sizeof(DebuggerIPCEvent)
         // This seems ugly, in this case we know the exact size of the event we want to read
         // why copy over all the extra data?
-        DebuggerIPCEvent *retEvent = (DebuggerIPCEvent *) _alloca(CorDBIPC_BUFFER_SIZE);
+        DebuggerIPCEvent *retEvent = (DebuggerIPCEvent *) Alloca(CorDBIPC_BUFFER_SIZE);
 
         {
             //
