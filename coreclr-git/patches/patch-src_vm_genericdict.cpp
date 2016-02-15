$NetBSD$

--- src/vm/genericdict.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/genericdict.cpp
@@ -829,7 +829,7 @@ Dictionary::PopulateEntry(
                 if (!ClrSafeInt<SIZE_T>::multiply(nargs, sizeof(TypeHandle), cbMem/* passed by ref */))
                     ThrowHR(COR_E_OVERFLOW);
                         
-                TypeHandle * pInst = (TypeHandle*) _alloca(cbMem);
+                TypeHandle * pInst = (TypeHandle*) Alloca(cbMem);
                 for (DWORD i = 0; i < nargs; i++)
                 {
                     pInst[i] = ptr.GetTypeHandleThrowing(
