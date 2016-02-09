$NetBSD$

--- src/vm/amd64/umthunkstub.S.orig	2016-02-06 09:37:43.000000000 +0000
+++ src/vm/amd64/umthunkstub.S
@@ -17,7 +17,7 @@ NESTED_ENTRY TheUMEntryPrestub, _TEXT, U
     END_PROLOGUE
 
     mov rdi, METHODDESC_REGISTER 
-    call C_FUNC(TheUMEntryPrestubWorker)
+    call EXTERNAL_C_FUNC(TheUMEntryPrestubWorker)
     
     // we're going to tail call to the exec stub that we just setup 
 
@@ -75,7 +75,7 @@ NESTED_ENTRY UMThunkStub, _TEXT, Unhandl
         //
         // Call GetThread()
         //
-        call            C_FUNC(GetThread)
+        call            EXTERNAL_C_FUNC(GetThread)
         test            rax, rax
         jz              LOCAL_LABEL(DoThreadSetup)
 
@@ -152,17 +152,17 @@ LOCAL_LABEL(PostCall):
 
 
 LOCAL_LABEL(DoThreadSetup):
-        call            C_FUNC(CreateThreadBlockThrow)
+        call            EXTERNAL_C_FUNC(CreateThreadBlockThrow)
         jmp             LOCAL_LABEL(HaveThread)
         
 LOCAL_LABEL(InvalidTransition):
         //No arguments to setup , ReversePInvokeBadTransition will failfast
-        call            C_FUNC(ReversePInvokeBadTransition)
+        call            EXTERNAL_C_FUNC(ReversePInvokeBadTransition)
 
 LOCAL_LABEL(DoTrapReturningThreadsTHROW):
         mov             rdi, r12                                                                        // Thread* pThread
         mov             rsi, [rbp - UMThunkStubAMD64_RBP_OFFSET + UMThunkStubAMD64_METHODDESC_OFFSET]   // UMEntryThunk* pUMEntry
-        call            C_FUNC(UMThunkStubRareDisableWorker)
+        call            EXTERNAL_C_FUNC(UMThunkStubRareDisableWorker)
 
         jmp             LOCAL_LABEL(InCooperativeMode)
 
