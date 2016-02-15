$NetBSD$

--- src/vm/reflectioninvocation.cpp.orig	2016-02-06 18:10:53.000000000 +0000
+++ src/vm/reflectioninvocation.cpp
@@ -543,7 +543,7 @@ FCIMPL6(Object*, RuntimeTypeHandle::Crea
         }
  
         INT32 rank = atd->GetRank();
-        INT32* lengths = (INT32*) _alloca(sizeof(INT32) * rank);
+        INT32* lengths = (INT32*) Alloca(sizeof(INT32) * rank);
         for (INT32 i = 0; i < rank; ++i)
         {
             lengths[i] = 0;
@@ -1076,7 +1076,7 @@ OBJECTREF InvokeArrayConstructor(ArrayTy
     if (!ClrSafeInt<int>::multiply(sizeof(INT32), argCnt, allocSize))
         COMPlusThrow(kArgumentException, IDS_EE_SIGTOOCOMPLEX);
         
-    INT32* indexes = (INT32*) _alloca((size_t)allocSize);
+    INT32* indexes = (INT32*) Alloca((size_t)allocSize);
     ZeroMemory(indexes, allocSize);
 
     for (i=0; i<(DWORD)argCnt; i++)
@@ -1446,7 +1446,7 @@ FCIMPL4(Object*, RuntimeMethodHandle::In
     // and second time to actually make the call.
     INTERIOR_STACK_PROBE_FOR(pThread, 1 + static_cast<UINT>((2 * nAllocaSize) / OS_PAGE_SIZE) + static_cast<UINT>(HOLDER_CODE_NORMAL_STACK_LIMIT));
 
-    LPBYTE pAlloc = (LPBYTE)_alloca(nAllocaSize);
+    LPBYTE pAlloc = (LPBYTE)Alloca(nAllocaSize);
 
     LPBYTE pTransitionBlock = pAlloc + TransitionBlock::GetNegSpaceSize();
 
@@ -1559,10 +1559,10 @@ FCIMPL4(Object*, RuntimeMethodHandle::In
         if (pMT->IsStructRequiringStackAllocRetBuf())
         {
             SIZE_T sz = pMT->GetNumInstanceFieldBytes();
-            pRetBufStackCopy = _alloca(sz);
+            pRetBufStackCopy = Alloca(sz);
             memset(pRetBufStackCopy, 0, sz);
 
-            pValueClasses = new (_alloca(sizeof(ValueClassInfo))) ValueClassInfo(pRetBufStackCopy, pMT, pValueClasses);
+            pValueClasses = new (Alloca(sizeof(ValueClassInfo))) ValueClassInfo(pRetBufStackCopy, pMT, pValueClasses);
             *((LPVOID*) (pTransitionBlock + argit.GetRetBuffArgOffset())) = pRetBufStackCopy;
         }
         else
@@ -1628,19 +1628,19 @@ FCIMPL4(Object*, RuntimeMethodHandle::In
 
             PVOID pArgDst = argDest.GetDestinationAddress();
 
-            PVOID pStackCopy = _alloca(structSize);
+            PVOID pStackCopy = Alloca(structSize);
             *(PVOID *)pArgDst = pStackCopy;
             pArgDst = pStackCopy;
 
             if (!nullableType.IsNull())
             {
-                byRefToNullables = new(_alloca(sizeof(ByRefToNullable))) ByRefToNullable(i, pStackCopy, nullableType, byRefToNullables);
+                byRefToNullables = new(Alloca(sizeof(ByRefToNullable))) ByRefToNullable(i, pStackCopy, nullableType, byRefToNullables);
             }
 
             // save the info into ValueClassInfo
             if (pMT->ContainsPointers()) 
             {
-                pValueClasses = new (_alloca(sizeof(ValueClassInfo))) ValueClassInfo(pStackCopy, pMT, pValueClasses);
+                pValueClasses = new (Alloca(sizeof(ValueClassInfo))) ValueClassInfo(pStackCopy, pMT, pValueClasses);
             }
 
             // We need a new ArgDestination that points to the stack copy
