$NetBSD$

--- src/vm/amd64/pinvokestubs.S.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/amd64/pinvokestubs.S
@@ -22,7 +22,7 @@ LEAF_ENTRY GenericPInvokeCalliHelper, _T
         //
         mov             rax, [PINVOKE_CALLI_SIGTOKEN_REGISTER + OFFSETOF__VASigCookie__pNDirectILStub]
         test            rax, rax
-        jz              C_FUNC(GenericPInvokeCalliGenILStub)
+        jz              EXTERNAL_C_FUNC(GenericPInvokeCalliGenILStub)
 
         //
         // We need to distinguish between a MethodDesc* and an unmanaged target in PInvokeStubForHost().
@@ -55,7 +55,7 @@ NESTED_ENTRY GenericPInvokeCalliGenILStu
         lea             rdi, [rsp + __PWTB_TransitionBlock]     // pTransitionBlock*
         mov             rsi, PINVOKE_CALLI_SIGTOKEN_REGISTER    // pVASigCookie
         mov             rdx, METHODDESC_REGISTER                // pUnmanagedTarget
-        call            C_FUNC(GenericPInvokeCalliStubWorker)
+        call            EXTERNAL_C_FUNC(GenericPInvokeCalliStubWorker)
 
         //
         // restore target
@@ -115,7 +115,7 @@ NESTED_ENTRY VarargPInvokeGenILStub, _TE
         lea             rdi, [rsp + __PWTB_TransitionBlock]     // pTransitionBlock*
         mov             rsi, PINVOKE_CALLI_SIGTOKEN_REGISTER    // pVASigCookie
         mov             rdx, METHODDESC_REGISTER                // pMD
-        call            C_FUNC(VarargPInvokeStubWorker)
+        call            EXTERNAL_C_FUNC(VarargPInvokeStubWorker)
 
         //
         // restore target
