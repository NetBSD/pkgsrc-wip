$NetBSD$

--- src/vm/amd64/virtualcallstubamd64.S.orig	2016-02-06 09:37:43.000000000 +0000
+++ src/vm/amd64/virtualcallstubamd64.S
@@ -35,7 +35,7 @@ NESTED_ENTRY ResolveWorkerAsmStub, _TEXT
         and             rcx,  7                                    // flags
         sub             rsi, rcx                                   // indirection cell
 
-        call            C_FUNC(VSD_ResolveWorker)
+        call            EXTERNAL_C_FUNC(VSD_ResolveWorker)
 
         EPILOG_WITH_TRANSITION_BLOCK_TAILCALL
         TAILJMP_RAX
@@ -99,7 +99,7 @@ NESTED_ENTRY StubDispatchFixupStub, _TEX
         mov             rdx,0                               // sectionIndex
         mov             rcx,0                               // pModule
 
-        call            C_FUNC(StubDispatchFixupWorker)
+        call            EXTERNAL_C_FUNC(StubDispatchFixupWorker)
 
         EPILOG_WITH_TRANSITION_BLOCK_TAILCALL
 PATCH_LABEL StubDispatchFixupPatchLabel
