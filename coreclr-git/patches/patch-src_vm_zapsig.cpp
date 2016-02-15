$NetBSD$

--- src/vm/zapsig.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/zapsig.cpp
@@ -915,7 +915,7 @@ MethodDesc *ZapSig::DecodeMethod(Module 
         if (!ClrSafeInt<SIZE_T>::multiply(nargs, sizeof(TypeHandle), cbMem/* passed by ref */))
             ThrowHR(COR_E_OVERFLOW);
                         
-        TypeHandle * pInst = (TypeHandle*) _alloca(cbMem);
+        TypeHandle * pInst = (TypeHandle*) Alloca(cbMem);
 
         for (DWORD i = 0; i < nargs; i++)
         {
