$NetBSD$

--- src/debug/ee/funceval.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/ee/funceval.cpp
@@ -1534,7 +1534,7 @@ void ResolveFuncEvalGenericArgInfo(Debug
     {
         ThrowHR(COR_E_OVERFLOW);
     }
-    TypeHandle * pGenericArgs = (nGenericArgs == 0) ? NULL : (TypeHandle *) _alloca(cbAllocSize);
+    TypeHandle * pGenericArgs = (nGenericArgs == 0) ? NULL : (TypeHandle *) Alloca(cbAllocSize);
 
     //
     // Snag the type arguments from the input and get the
@@ -3203,7 +3203,7 @@ static void DoNormalFuncEval( DebuggerEv
     {
         ThrowHR(COR_E_OVERFLOW);
     }
-    FuncEvalArgInfo * pFEArgInfo = (FuncEvalArgInfo *)_alloca(cbAllocSize);
+    FuncEvalArgInfo * pFEArgInfo = (FuncEvalArgInfo *)Alloca(cbAllocSize);
     memset(pFEArgInfo, 0, cbAllocSize);
 
     GatherFuncEvalArgInfo(pDE, mSig, argData, pFEArgInfo);
@@ -3275,7 +3275,7 @@ static void DoNormalFuncEval( DebuggerEv
     {
         ThrowHR(COR_E_OVERFLOW);
     }
-    ARG_SLOT * pArguments = (ARG_SLOT *)_alloca(cbAllocSize);
+    ARG_SLOT * pArguments = (ARG_SLOT *)Alloca(cbAllocSize);
     memset(pArguments, 0, cbAllocSize);
 
     LPVOID pRetBuff = NULL;
@@ -3385,7 +3385,7 @@ static void GCProtectArgsAndDoNormalFunc
     {
         ThrowHR(COR_E_OVERFLOW);
     }
-    OBJECTREF * pObjectRefArray = (OBJECTREF*)_alloca(cbAllocSize);
+    OBJECTREF * pObjectRefArray = (OBJECTREF*)Alloca(cbAllocSize);
     memset(pObjectRefArray, 0, cbAllocSize);
     GCPROTECT_ARRAY_BEGIN(*pObjectRefArray, pDE->m_argCount);
 
@@ -3398,7 +3398,7 @@ static void GCProtectArgsAndDoNormalFunc
     {
         ThrowHR(COR_E_OVERFLOW);
     }
-    void ** pMaybeInteriorPtrArray = (void **)_alloca(cbAllocSize);
+    void ** pMaybeInteriorPtrArray = (void **)Alloca(cbAllocSize);
     memset(pMaybeInteriorPtrArray, 0, cbAllocSize);
     GCPROTECT_BEGININTERIOR_ARRAY(*pMaybeInteriorPtrArray, (UINT)(cbAllocSize/sizeof(OBJECTREF)));
 
@@ -3413,7 +3413,7 @@ static void GCProtectArgsAndDoNormalFunc
     {
         ThrowHR(COR_E_OVERFLOW);
     }
-    void ** pByRefMaybeInteriorPtrArray = (void **)_alloca(cbAllocSize);
+    void ** pByRefMaybeInteriorPtrArray = (void **)Alloca(cbAllocSize);
     memset(pByRefMaybeInteriorPtrArray, 0, cbAllocSize);
     GCPROTECT_BEGININTERIOR_ARRAY(*pByRefMaybeInteriorPtrArray, (UINT)(cbAllocSize/sizeof(OBJECTREF)));
 
@@ -3426,7 +3426,7 @@ static void GCProtectArgsAndDoNormalFunc
     {
         ThrowHR(COR_E_OVERFLOW);
     }
-    INT64 *pBufferForArgsArray = (INT64*)_alloca(cbAllocSize);
+    INT64 *pBufferForArgsArray = (INT64*)Alloca(cbAllocSize);
     memset(pBufferForArgsArray, 0, cbAllocSize);
 
     FrameWithCookie<ProtectValueClassFrame> protectValueClassFrame;
@@ -3539,7 +3539,7 @@ void FuncEvalHijackRealWorker(DebuggerEv
         {
             ThrowHR(COR_E_OVERFLOW);
         }
-        TypeHandle *pGenericArgs = (nGenericArgs == 0) ? NULL : (TypeHandle *) _alloca(cbAllocSize);
+        TypeHandle *pGenericArgs = (nGenericArgs == 0) ? NULL : (TypeHandle *) Alloca(cbAllocSize);
         //
         // Snag the type arguments from the input and get the
         // method desc that corresponds to the instantiated desc.
