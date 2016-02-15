$NetBSD$

--- src/vm/securityattributes.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/securityattributes.cpp
@@ -373,10 +373,10 @@ Assembly* SecurityAttributes::LoadAssemb
     _ASSERTE(SUCCEEDED(hr));
 
     // Allocate the necessary buffers.
-    wszName = (LPWSTR)_alloca(cchName * sizeof(WCHAR));
-    sContext.szLocale = (LPWSTR)_alloca(sContext.cbLocale * sizeof(WCHAR));
-    sContext.rProcessor = (DWORD *)_alloca(sContext.ulProcessor * sizeof(DWORD));
-    sContext.rOS = (OSINFO *)_alloca(sContext.ulOS * sizeof(OSINFO));
+    wszName = (LPWSTR)Alloca(cchName * sizeof(WCHAR));
+    sContext.szLocale = (LPWSTR)Alloca(sContext.cbLocale * sizeof(WCHAR));
+    sContext.rProcessor = (DWORD *)Alloca(sContext.ulProcessor * sizeof(DWORD));
+    sContext.rOS = (OSINFO *)Alloca(sContext.ulOS * sizeof(OSINFO));
 
     // Get the assembly name and rest of naming properties.
     hr = pImport->GetAssemblyRefProps(tkAssemblyRef,
@@ -887,7 +887,7 @@ HRESULT SecurityAttributes::SetAttrField
 
             DWORD allocLen = cbName + 1;
             // Buffer and nul terminate it.
-            szString = (LPSTR)_alloca(allocLen);
+            szString = (LPSTR)Alloca(allocLen);
             memcpy(szString, pbName, cbName);
             szString[cbName] = '\0';
 
@@ -1043,7 +1043,7 @@ HRESULT SecurityAttributes::SetAttrPrope
 
             if ((pbName - *ppbBuffer) < 4) {
                 // Buffer and nul terminate it.
-                szString = (LPSTR)_alloca(allocLen);
+                szString = (LPSTR)Alloca(allocLen);
             } else {
                 tmpLargeStringHolder = new BYTE[allocLen];                
                 szString = (LPSTR) ((BYTE*)tmpLargeStringHolder);
@@ -1145,7 +1145,7 @@ void SecurityAttributes::AttrSetBlobToPe
     GCPROTECT_BEGIN(throwable);
     {
         // allocate and GC-protect an array of objectrefs to reference the permissions
-        OBJECTREF* attrArray = (OBJECTREF*)_alloca(pset.dwAttrCount * sizeof(OBJECTREF));
+        OBJECTREF* attrArray = (OBJECTREF*)Alloca(pset.dwAttrCount * sizeof(OBJECTREF));
         memset(attrArray, 0, pset.dwAttrCount * sizeof(OBJECTREF));
         GCPROTECT_ARRAY_BEGIN(*attrArray, pset.dwAttrCount);
         {
@@ -1223,7 +1223,7 @@ HRESULT SecurityAttributes::TranslateSec
                 SetupRestrictSecAttributes();
 
                 // allocate and protect an array of objectrefs to reference the permissions
-                attrArray = (OBJECTREF*)_alloca(pAttrSet->dwAttrCount * sizeof(OBJECTREF));
+                attrArray = (OBJECTREF*)Alloca(pAttrSet->dwAttrCount * sizeof(OBJECTREF));
                 memset(attrArray, 0, pAttrSet->dwAttrCount * sizeof(OBJECTREF));
                 GCPROTECT_ARRAY_BEGIN(*attrArray, pAttrSet->dwAttrCount);
                 {
@@ -1900,7 +1900,7 @@ bool SecurityAttributes::IsUnrestrictedP
     if (allocLen < cbName)
         return false;
 
-    LPSTR szName = (LPSTR)_alloca(allocLen);
+    LPSTR szName = (LPSTR)Alloca(allocLen);
     memcpy(szName, pbName, cbName);
     szName[cbName] = '\0';
 
@@ -1965,7 +1965,7 @@ HRESULT SecurityAttributes::FixUpPermiss
 
     // Buffer the name of the property and null terminate it.
     DWORD allocLen = cbName + 1;
-    LPSTR szName = (LPSTR)_alloca(allocLen);
+    LPSTR szName = (LPSTR)Alloca(allocLen);
     memcpy(szName, pbName, cbName);
     szName[cbName] = '\0';
 
@@ -2098,7 +2098,7 @@ HRESULT GetFullyQualifiedTypeName(SStrin
             return hr;
 
         // Get the assembly name other naming properties
-        wszAssemblyName = (LPWSTR)_alloca(cchName * sizeof(WCHAR));
+        wszAssemblyName = (LPWSTR)Alloca(cchName * sizeof(WCHAR));
         hr = pImport->GetAssemblyProps(tkAssemblyRef,
                                             (const void **)&pbPublicKeyOrToken,
                                             &cbPublicKeyOrToken,
@@ -2128,7 +2128,7 @@ HRESULT GetFullyQualifiedTypeName(SStrin
             return hr;
 
         // Get the assembly name other naming properties
-        wszAssemblyName = (LPWSTR)_alloca(cchName * sizeof(WCHAR));
+        wszAssemblyName = (LPWSTR)Alloca(cchName * sizeof(WCHAR));
         hr = pImport->GetAssemblyRefProps(tkAssemblyRef,
                                             (const void **)&pbPublicKeyOrToken,
                                             &cbPublicKeyOrToken,
