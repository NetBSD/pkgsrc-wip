$NetBSD$

--- src/debug/ee/debugger.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/ee/debugger.h
@@ -3643,7 +3643,7 @@ template<class T> void DeleteInteropSafe
 
     if (p != NULL)
     {
-        p->~T();
+//        p->~T();
 
         _ASSERTE(g_pDebugger != NULL);
         DebuggerHeap * pHeap = g_pDebugger->GetInteropSafeHeap_NoThrow();
@@ -3973,4 +3973,3 @@ void FixupDispatcherContext(T_DISPATCHER
 #endif
 
 #endif /* DEBUGGER_H_ */
-
