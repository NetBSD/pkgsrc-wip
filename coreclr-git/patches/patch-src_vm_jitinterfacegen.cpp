$NetBSD$

--- src/vm/jitinterfacegen.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/jitinterfacegen.cpp
@@ -224,10 +224,10 @@ void InitJITHelpers1()
         if (GCHeap::UseAllocationContexts())
         {
 #ifdef FEATURE_IMPLICIT_TLS
-            SetJitHelperFunction(CORINFO_HELP_NEWSFAST, JIT_NewS_MP_FastPortable);
-            SetJitHelperFunction(CORINFO_HELP_NEWSFAST_ALIGN8, JIT_NewS_MP_FastPortable);
-            SetJitHelperFunction(CORINFO_HELP_NEWARR_1_VC, JIT_NewArr1VC_MP_FastPortable);
-            SetJitHelperFunction(CORINFO_HELP_NEWARR_1_OBJ, JIT_NewArr1OBJ_MP_FastPortable);
+            SetJitHelperFunction(CORINFO_HELP_NEWSFAST, reinterpret_cast<void*>(JIT_NewS_MP_FastPortable));
+            SetJitHelperFunction(CORINFO_HELP_NEWSFAST_ALIGN8, reinterpret_cast<void*>(JIT_NewS_MP_FastPortable));
+            SetJitHelperFunction(CORINFO_HELP_NEWARR_1_VC, reinterpret_cast<void*>(JIT_NewArr1VC_MP_FastPortable));
+            SetJitHelperFunction(CORINFO_HELP_NEWARR_1_OBJ, reinterpret_cast<void*>(JIT_NewArr1OBJ_MP_FastPortable));
 
             ECall::DynamicallyAssignFCallImpl(GetEEFuncEntryPoint(AllocateString_MP_FastPortable), ECall::FastAllocateString);
 #else // !FEATURE_IMPLICIT_TLS
