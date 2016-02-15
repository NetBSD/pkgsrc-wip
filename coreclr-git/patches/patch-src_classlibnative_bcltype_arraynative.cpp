$NetBSD$

--- src/classlibnative/bcltype/arraynative.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/classlibnative/bcltype/arraynative.cpp
@@ -1306,7 +1306,7 @@ FCIMPL4(Object*, ArrayNative::CreateInst
             if (!ClrSafeInt<DWORD>::multiply(boundsSize, sizeof(INT32), dwAllocaSize))
                 COMPlusThrowOM();
 
-            bounds = (INT32*) _alloca(dwAllocaSize);
+            bounds = (INT32*) Alloca(dwAllocaSize);
 
             for (int i=0;i<rank;i++) {
                 bounds[2*i] = pLowerBounds[i];
@@ -1320,7 +1320,7 @@ FCIMPL4(Object*, ArrayNative::CreateInst
             if (!ClrSafeInt<DWORD>::multiply(boundsSize, sizeof(INT32), dwAllocaSize))
                 COMPlusThrowOM();
 
-            bounds = (INT32*) _alloca(dwAllocaSize);
+            bounds = (INT32*) Alloca(dwAllocaSize);
 
             // We need to create a private copy of pLengths to avoid holes caused
             // by caller mutating the array
