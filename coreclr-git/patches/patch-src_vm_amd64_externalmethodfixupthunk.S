$NetBSD$

--- src/vm/amd64/externalmethodfixupthunk.S.orig	2016-02-06 09:37:43.000000000 +0000
+++ src/vm/amd64/externalmethodfixupthunk.S
@@ -18,7 +18,7 @@ NESTED_ENTRY ExternalMethodFixupStub, _T
         mov             rdx, 0                              // sectionIndex
         mov             rcx, 0                              // pModule
 
-        call            C_FUNC(ExternalMethodFixupWorker)
+        call            EXTERNAL_C_FUNC(ExternalMethodFixupWorker)
 
         EPILOG_WITH_TRANSITION_BLOCK_TAILCALL
 PATCH_LABEL ExternalMethodFixupPatchLabel
@@ -35,7 +35,7 @@ NESTED_ENTRY DelayLoad_MethodCall, _TEXT
         lea     rdi, [rsp + __PWTB_TransitionBlock] // pTransitionBlock
         mov     rsi, rax                            // pIndirection
 
-        call            C_FUNC(ExternalMethodFixupWorker)
+        call            EXTERNAL_C_FUNC(ExternalMethodFixupWorker)
 
         EPILOG_WITH_TRANSITION_BLOCK_TAILCALL
 
@@ -56,7 +56,7 @@ NESTED_ENTRY DelayLoad_Helper\suffix, _T
         lea     rdi, [rsp + __PWTB_TransitionBlock] // pTransitionBlock
         mov     rsi, rax                            // pIndirection
 
-        call    C_FUNC(DynamicHelperWorker)
+        call    EXTERNAL_C_FUNC(DynamicHelperWorker)
 
         test    rax,rax
         jnz     LOCAL_LABEL(TailCallDelayLoad_Helper\suffix)
@@ -89,7 +89,7 @@ NESTED_ENTRY VirtualMethodFixupStub, _TE
 
         lea             rdi, [rsp + __PWTB_TransitionBlock] // pTransitionBlock
         sub             rsi, 5                              // pThunk
-        call            C_FUNC(VirtualMethodFixupWorker)
+        call            EXTERNAL_C_FUNC(VirtualMethodFixupWorker)
 
         EPILOG_WITH_TRANSITION_BLOCK_TAILCALL
 PATCH_LABEL VirtualMethodFixupPatchLabel
