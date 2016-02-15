$NetBSD$

--- src/vm/dispatchinfo.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/dispatchinfo.cpp
@@ -1267,14 +1267,14 @@ void DispatchInfo::InvokeMemberWorker(Di
     HRESULT hr;
     
     // Allocate the array of used flags.
-    BYTE *aArgUsedFlags = (BYTE*)_alloca(NumParams * sizeof(BYTE));
+    BYTE *aArgUsedFlags = (BYTE*)Alloca(NumParams * sizeof(BYTE));
     memset(aArgUsedFlags, 0, NumParams * sizeof(BYTE));
 
     size_t cbByrefArgMngVariantIndex;
     if (!ClrSafeInt<size_t>::multiply(sizeof(DWORD), NumArgs, cbByrefArgMngVariantIndex))
         ThrowHR(COR_E_OVERFLOW);
 
-    DWORD *aByrefArgMngVariantIndex = (DWORD *)_alloca(cbByrefArgMngVariantIndex);
+    DWORD *aByrefArgMngVariantIndex = (DWORD *)Alloca(cbByrefArgMngVariantIndex);
 
     
     //
@@ -2182,7 +2182,7 @@ HRESULT DispatchInfo::InvokeMember(Simpl
         if (!ClrSafeInt<size_t>::multiply(sizeof(OBJECTHANDLE *), NumArgs, cbStaticArrayBackupObjHandle))
             ThrowHR(COR_E_OVERFLOW);
 
-        OBJECTHANDLE *aByrefStaticArrayBackupObjHandle = (OBJECTHANDLE *)_alloca(cbStaticArrayBackupObjHandle);
+        OBJECTHANDLE *aByrefStaticArrayBackupObjHandle = (OBJECTHANDLE *)Alloca(cbStaticArrayBackupObjHandle);
         memset(aByrefStaticArrayBackupObjHandle, 0, cbStaticArrayBackupObjHandle);
 
         // Allocate the array that maps method params to their indices.
@@ -2190,14 +2190,14 @@ HRESULT DispatchInfo::InvokeMember(Simpl
         if (!ClrSafeInt<size_t>::multiply(sizeof(int), NumArgs, cbManagedMethodParamIndexMap))
             ThrowHR(COR_E_OVERFLOW);
 
-        int *pManagedMethodParamIndexMap = (int *)_alloca(cbManagedMethodParamIndexMap);
+        int *pManagedMethodParamIndexMap = (int *)Alloca(cbManagedMethodParamIndexMap);
 
         // Allocate the array of byref objects.
         size_t cbByrefArgOleVariant;
         if (!ClrSafeInt<size_t>::multiply(sizeof(VARIANT *), NumArgs, cbByrefArgOleVariant))
             ThrowHR(COR_E_OVERFLOW);
 
-        VARIANT **aByrefArgOleVariant = (VARIANT **)_alloca(cbByrefArgOleVariant);
+        VARIANT **aByrefArgOleVariant = (VARIANT **)Alloca(cbByrefArgOleVariant);
       
         Objs.Target = pSimpleWrap->GetObjectRef();
 
