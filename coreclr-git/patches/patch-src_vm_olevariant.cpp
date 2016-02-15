$NetBSD$

--- src/vm/olevariant.cpp.orig	2016-02-02 01:31:09.000000000 +0000
+++ src/vm/olevariant.cpp
@@ -4506,7 +4506,7 @@ BASEARRAYREF OleVariant::CreateArrayRefF
         // and element pairs are presented before we call AllocateArrayEx().
         Rank = pSafeArray->cDims;
         cAllocateArrayArgs = Rank * 2;
-        pAllocateArrayArgs = (INT32*)_alloca(sizeof(INT32) * Rank * 2);
+        pAllocateArrayArgs = (INT32*)Alloca(sizeof(INT32) * Rank * 2);
         INT32 * pBoundsPtr = pAllocateArrayArgs;
 
         // Copy the lower bounds and count of elements for the dimensions. These
@@ -4758,10 +4758,10 @@ void OleVariant::TransposeArrayData(BYTE
     CONTRACTL_END;
 
     int iDims;
-    DWORD *aDestElemCount = (DWORD*)_alloca(pSafeArray->cDims * sizeof(DWORD));
-    DWORD *aDestIndex = (DWORD*)_alloca(pSafeArray->cDims * sizeof(DWORD));
-    BYTE **aDestDataPos = (BYTE **)_alloca(pSafeArray->cDims * sizeof(BYTE *));
-    SIZE_T *aDestDelta = (SIZE_T*)_alloca(pSafeArray->cDims * sizeof(SIZE_T));
+    DWORD *aDestElemCount = (DWORD*)Alloca(pSafeArray->cDims * sizeof(DWORD));
+    DWORD *aDestIndex = (DWORD*)Alloca(pSafeArray->cDims * sizeof(DWORD));
+    BYTE **aDestDataPos = (BYTE **)Alloca(pSafeArray->cDims * sizeof(BYTE *));
+    SIZE_T *aDestDelta = (SIZE_T*)Alloca(pSafeArray->cDims * sizeof(SIZE_T));
     CQuickArray<BYTE> TmpArray;
 
     // If there are no components, then there we are done.
@@ -4917,7 +4917,7 @@ BASEARRAYREF OleVariant::ExtractWrappedO
 
     // Set up the bounds arguments.
     DWORD numArgs =  rank*2;
-        INT32* args = (INT32*) _alloca(sizeof(INT32)*numArgs);
+        INT32* args = (INT32*) Alloca(sizeof(INT32)*numArgs);
     
     if (bIsMDArray)
     {
