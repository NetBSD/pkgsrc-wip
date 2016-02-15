$NetBSD$

--- src/vm/threadsuspend.cpp.orig	2016-02-08 23:48:23.000000000 +0000
+++ src/vm/threadsuspend.cpp
@@ -4275,7 +4275,7 @@ void __stdcall Thread::RedirectedHandled
             // Free the context struct if we already have one cached
             if (pThread->GetSavedRedirectContext())
             {
-                CONTEXT* pCtxTemp = (CONTEXT*)_alloca(sizeof(CONTEXT));
+                CONTEXT* pCtxTemp = (CONTEXT*)Alloca(sizeof(CONTEXT));
                 memcpy(pCtxTemp, pCtx, sizeof(CONTEXT));
                 delete pCtx;
                 pCtx = pCtxTemp;
@@ -6736,7 +6736,7 @@ void Thread::SetSafeEvent()
  * WaitSuspendEventsHelper
  *
  * This function is a simple helper function for WaitSuspendEvents.  It is needed
- * because of the EX_TRY macro.  This macro does an alloca(), which allocates space
+ * because of the EX_TRY macro.  This macro does an Alloca(), which allocates space
  * off the stack, not free'ing it.  Thus, doing a EX_TRY in a loop can easily result
  * in a stack overflow error.  By factoring out the EX_TRY into a separate function,
  * we recover that stack space.
