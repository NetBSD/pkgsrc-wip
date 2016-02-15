$NetBSD$

--- src/vm/stackbuildersink.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/stackbuildersink.cpp
@@ -294,7 +294,7 @@ void CallDescrWithObjectArray(OBJECTREF&
     if (!ClrSafeInt<UINT32>::addition(cbAlloc, nStackBytes, cbAlloc))
         COMPlusThrow(kArgumentException);
 
-    pAlloc = (LPBYTE)_alloca(cbAlloc);
+    pAlloc = (LPBYTE)Alloca(cbAlloc);
     pTransitionBlock = pAlloc + TransitionBlock::GetNegSpaceSize();
 
     // cycle through the parameters and see if there are byrefs
@@ -385,7 +385,7 @@ void CallDescrWithObjectArray(OBJECTREF&
     int    ofs = 0;
 
     // REVIEW: need to use actual arg count if VarArgs are supported
-    ArgInfo* pArgInfoStart = (ArgInfo*) _alloca(nFixedArgs*sizeof(ArgInfo));
+    ArgInfo* pArgInfoStart = (ArgInfo*) Alloca(nFixedArgs*sizeof(ArgInfo));
 
 #ifdef _DEBUG
     // We expect to write useful data over every part of this so need
@@ -434,7 +434,7 @@ void CallDescrWithObjectArray(OBJECTREF&
                 numByRef ++;
             }
 
-            ByRefInfo *brInfo = (ByRefInfo *) _alloca(offsetof(ByRefInfo,data) + pArgInfo->dataSize);
+            ByRefInfo *brInfo = (ByRefInfo *) Alloca(offsetof(ByRefInfo,data) + pArgInfo->dataSize);
             brInfo->argIndex = arg;
             brInfo->typ = brType;
             brInfo->typeHandle = ty;
@@ -478,9 +478,9 @@ void CallDescrWithObjectArray(OBJECTREF&
         if (pStructRetTypeMT->IsStructRequiringStackAllocRetBuf())
         {
             SIZE_T sz = pStructRetTypeMT->GetNumInstanceFieldBytes();
-            pRetBufData = pRetBufStackData = _alloca(sz);
+            pRetBufData = pRetBufStackData = Alloca(sz);
             memset(pRetBufData, 0, sz);
-            pValueClasses = new (_alloca(sizeof(ValueClassInfo))) ValueClassInfo(pRetBufStackData, pStructRetTypeMT, pValueClasses);
+            pValueClasses = new (Alloca(sizeof(ValueClassInfo))) ValueClassInfo(pRetBufStackData, pStructRetTypeMT, pValueClasses);
         }
         else
         {
@@ -581,11 +581,11 @@ void CallDescrWithObjectArray(OBJECTREF&
                     // We do not need to allocate a buffer if the argument is already passed by reference.
                     if (!pArgInfo->byref && ArgIterator::IsArgPassedByRef(dataTypeHandle))
                     {
-                        PVOID pvArg = _alloca(dataSize);
+                        PVOID pvArg = Alloca(dataSize);
                         pMT->UnBoxIntoUnchecked(pvArg, pArguments[i]);
                         *(PVOID*)dataLocation = pvArg;
 
-                        pValueClasses = new (_alloca(sizeof(ValueClassInfo))) ValueClassInfo(pvArg, pMT, pValueClasses);
+                        pValueClasses = new (Alloca(sizeof(ValueClassInfo))) ValueClassInfo(pvArg, pMT, pValueClasses);
                     }
                     else
 #endif
