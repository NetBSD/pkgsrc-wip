$NetBSD$

--- src/vm/array.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/array.cpp
@@ -661,7 +661,7 @@ MethodTable* Module::CreateArrayMethodTa
             SSIZE_T AllocSizeSeries;
             if (!ClrSafeInt<SSIZE_T>::multiply(sizeof(CGCDescSeries*), nSeries, AllocSizeSeries))
                 COMPlusThrowOM();
-            CGCDescSeries** sortedSeries = (CGCDescSeries**) _alloca(AllocSizeSeries);
+            CGCDescSeries** sortedSeries = (CGCDescSeries**) Alloca(AllocSizeSeries);
             int index;
             for (index = 0; index < nSeries; index++)
                 sortedSeries[index] = &pByValueSeries[-index];
@@ -1278,7 +1278,7 @@ Stub *GenerateArrayOpStub(ArrayMethodDes
 
     MethodTable *pMT = pMD->GetMethodTable();
 
-    ArrayOpScript *paos = (ArrayOpScript*)_alloca(sizeof(ArrayOpScript) + sizeof(ArrayOpIndexSpec) * pMT->GetRank());
+    ArrayOpScript *paos = (ArrayOpScript*)Alloca(sizeof(ArrayOpScript) + sizeof(ArrayOpIndexSpec) * pMT->GetRank());
 
     GenerateArrayOpScript(pMD, paos);
 
