$NetBSD$

--- src/vm/proftoeeinterfaceimpl.cpp.orig	2016-01-31 22:29:17.000000000 +0000
+++ src/vm/proftoeeinterfaceimpl.cpp
@@ -1123,7 +1123,7 @@ BOOL HeapWalkHelper(Object * pBO, void *
             if (bOnStack)
             {
                 // It's small enough, so just allocate on the stack
-                arrObjRef = (OBJECTREF *)_alloca(cNumRefs * sizeof(OBJECTREF));
+                arrObjRef = (OBJECTREF *)Alloca(cNumRefs * sizeof(OBJECTREF));
             }
             else
             {
@@ -9716,7 +9716,7 @@ HCIMPL2(EXTERN_C void, ProfileEnter, UIN
             }
             
             ulArgInfoSize = sizeof(COR_PRF_FUNCTION_ARGUMENT_INFO) + count * sizeof(COR_PRF_FUNCTION_ARGUMENT_RANGE);
-            pArgumentInfo = (COR_PRF_FUNCTION_ARGUMENT_INFO *)_alloca(ulArgInfoSize);
+            pArgumentInfo = (COR_PRF_FUNCTION_ARGUMENT_INFO *)Alloca(ulArgInfoSize);
         }
 
         HRESULT hr = ProfilingGetFunctionEnter3Info(functionId, (COR_PRF_ELT_INFO)&eltInfo, &frameInfo, &ulArgInfoSize, pArgumentInfo);
