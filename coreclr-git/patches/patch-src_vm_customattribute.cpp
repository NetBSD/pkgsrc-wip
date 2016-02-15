$NetBSD$

--- src/vm/customattribute.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/customattribute.cpp
@@ -576,7 +576,7 @@ FCIMPL5(VOID, Attribute::ParseAttributeA
             size_t size = sizeof(CaArg) * cArgs;
             if ((size / sizeof(CaArg)) != cArgs) // uint over/underflow
                 IfFailGo(E_INVALIDARG);
-            pCaArgs = (CaArg*)_alloca(size);
+            pCaArgs = (CaArg*)Alloca(size);
             
             for (COUNT_T i = 0; i < cArgs; i ++)
             {
@@ -596,7 +596,7 @@ FCIMPL5(VOID, Attribute::ParseAttributeA
             size_t size = sizeof(CaNamedArg) * cNamedArgs;
             if ((size / sizeof(CaNamedArg)) != cNamedArgs) // uint over/underflow
                 IfFailGo(E_INVALIDARG);
-            pCaNamedArgs = (CaNamedArg*)_alloca(size);
+            pCaNamedArgs = (CaNamedArg*)Alloca(size);
 
             for (COUNT_T i = 0; i < cNamedArgs; i ++)
             {
@@ -764,10 +764,10 @@ FCIMPL5(LPVOID, COMCustomAttribute::Crea
         UINT cArgs = pSig->NumFixedArgs() + 1; // make room for the this pointer
         UINT i = 1; // used to flag that we actually get the right number of arg from the blob
         
-        args = (ARG_SLOT*)_alloca(cArgs * sizeof(ARG_SLOT));
+        args = (ARG_SLOT*)Alloca(cArgs * sizeof(ARG_SLOT));
         memset((void*)args, 0, cArgs * sizeof(ARG_SLOT));
         
-        OBJECTREF *argToProtect = (OBJECTREF*)_alloca(cArgs * sizeof(OBJECTREF));
+        OBJECTREF *argToProtect = (OBJECTREF*)Alloca(cArgs * sizeof(OBJECTREF));
         memset((void*)argToProtect, 0, cArgs * sizeof(OBJECTREF));
 
         // If we relax this, we need to insure custom attributes construct properly for Nullable<T>
@@ -1207,7 +1207,7 @@ TypeHandle COMCustomAttribute::GetTypeHa
         if ((size+1 <= 1) || (size > endBlob - *pBlob))
             COMPlusThrow(kCustomAttributeFormatException);
 
-        LPUTF8 szName = (LPUTF8)_alloca(size + 1);
+        LPUTF8 szName = (LPUTF8)Alloca(size + 1);
         memcpy(szName, *pBlob, size);
         *pBlob += size;
         szName[size] = 0;
