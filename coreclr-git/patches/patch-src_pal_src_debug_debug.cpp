$NetBSD$

--- src/pal/src/debug/debug.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/debug/debug.cpp
@@ -146,7 +146,8 @@ FlushInstructionCache(
 
     if (lpBaseAddress != NULL)
     {
-        Ret = DBG_FlushInstructionCache(lpBaseAddress, dwSize);
+//        Ret = DBG_FlushInstructionCache(lpBaseAddress, dwSize);
+        Ret = TRUE;
     }
     else
     {
@@ -459,11 +460,13 @@ GetThreadContext(
     {
         if (!pTargetThread->IsDummy())
         {
+#if 0
             ret = CONTEXT_GetThreadContext(
                 GetCurrentProcessId(),
                 pTargetThread->GetPThreadSelf(),
                 lpContext
                 );
+#endif
         }
         else
         {
@@ -521,11 +524,13 @@ SetThreadContext(
     {
         if (!pTargetThread->IsDummy())
         {
+#if 0
             ret = CONTEXT_SetThreadContext(
                 GetCurrentProcessId(),
                 pTargetThread->GetPThreadSelf(),
                 lpContext
                 );
+#endif
         }
         else
         {
