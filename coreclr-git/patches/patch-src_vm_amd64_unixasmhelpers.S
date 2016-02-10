$NetBSD$

--- src/vm/amd64/unixasmhelpers.S.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/amd64/unixasmhelpers.S
@@ -26,7 +26,7 @@ LEAF_ENTRY PrecodeFixupThunk, _TEXT
         lea     METHODDESC_REGISTER,[rax+r11*8]
 
         // Tail call to prestub
-        jmp C_FUNC(ThePreStub)
+        jmp EXTERNAL_C_FUNC(ThePreStub)
 
 LEAF_END PrecodeFixupThunk, _TEXT
 
@@ -113,7 +113,7 @@ NESTED_ENTRY NDirectImportThunk, _TEXT, 
         // Call NDirectImportWorker w/ the NDirectMethodDesc*
         //
         mov             rdi, METHODDESC_REGISTER
-        call            C_FUNC(NDirectImportWorker)
+        call            EXTERNAL_C_FUNC(NDirectImportWorker)
         
         RESTORE_FLOAT_ARGUMENT_REGISTERS 0
 
@@ -160,7 +160,7 @@ NESTED_ENTRY JIT_RareDisableHelper, _TEX
     // Second float return register
     movdqa              xmmword ptr [rsp+0x10], xmm1
 
-    call                C_FUNC(JIT_RareDisableHelperWorker)
+    call                EXTERNAL_C_FUNC(JIT_RareDisableHelperWorker)
 
     movdqa              xmm0, xmmword ptr [rsp]
     movdqa              xmm1, xmmword ptr [rsp+0x10]
@@ -330,7 +330,7 @@ LEAF_ENTRY SinglecastDelegateInvokeStub,
                                                                                       
 NullObject:                                                                           
         mov     rdi, CORINFO_NullReferenceException_ASM                               
-        jmp     C_FUNC(JIT_InternalThrow)
+        jmp     EXTERNAL_C_FUNC(JIT_InternalThrow)
                                                                                       
 LEAF_END SinglecastDelegateInvokeStub, _TEXT
 
@@ -372,4 +372,3 @@ LEAF_ENTRY StartUnwindingNativeFrames, _
         mov     rdi, rsi 
         jmp     EXTERNAL_C_FUNC(ThrowExceptionHelper)
 LEAF_END StartUnwindingNativeFrames, _TEXT
-
