$NetBSD$

--- src/vm/amd64/theprestubamd64.S.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/amd64/theprestubamd64.S
@@ -14,7 +14,7 @@ NESTED_ENTRY ThePreStub, _TEXT, NoHandle
         //
         lea             rdi, [rsp + __PWTB_TransitionBlock]     // pTransitionBlock*
         mov             rsi, METHODDESC_REGISTER
-        call            C_FUNC(PreStubWorker)
+        call            EXTERNAL_C_FUNC(PreStubWorker)
 
         EPILOG_WITH_TRANSITION_BLOCK_TAILCALL
         TAILJMP_RAX
@@ -27,4 +27,3 @@ LEAF_ENTRY ThePreStubPatch, _TEXT
 PATCH_LABEL ThePreStubPatchLabel
         ret
 LEAF_END ThePreStubPatch, _TEXT
-
