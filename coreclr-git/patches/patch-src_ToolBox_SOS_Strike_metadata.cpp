$NetBSD$

--- src/ToolBox/SOS/Strike/metadata.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/Strike/metadata.cpp
@@ -41,7 +41,7 @@ static HRESULT NameForTypeDef_s(mdTypeDe
     if (hr != S_OK) {
         return hr;
     }
-    WCHAR *name = (WCHAR*)_alloca((nameLen+1)*sizeof(WCHAR));
+    WCHAR *name = (WCHAR*)alloca((nameLen+1)*sizeof(WCHAR));
     wcscpy_s (name, nameLen+1, mdName);
     hr = NameForTypeDef_s(tkEnclosingClass,pImport,mdName, capacity_mdName);
     if (hr != S_OK) {
@@ -75,8 +75,8 @@ static HRESULT NameForTypeDefNew(mdTypeD
 {
     DWORD flags;
     ULONG nameLen;
-    char *name = (char *)_alloca((mdNameLen+1)*sizeof(char));
-    char *namesp = (char *)_alloca((mdNameLen+1)*sizeof(char));
+    char *name = (char *)alloca((mdNameLen+1)*sizeof(char));
+    char *namesp = (char *)alloca((mdNameLen+1)*sizeof(char));
     
     HRESULT hr = pImport->GetNameOfTypeDef(tkTypeDef, name, namesp);
     if (FAILED(hr))
