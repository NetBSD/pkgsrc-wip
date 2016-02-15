$NetBSD$

--- src/vm/fusionbind.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/fusionbind.cpp
@@ -503,7 +503,7 @@ HRESULT FusionBind::AddEnvironmentProper
     WCHAR *pValue = &(rcValue[0]);
     size = WszGetEnvironmentVariable(variable, pValue, size);
     if(size > _MAX_PATH) {
-        pValue = (WCHAR*) _alloca(size * sizeof(WCHAR));
+        pValue = (WCHAR*) Alloca(size * sizeof(WCHAR));
         size = WszGetEnvironmentVariable(variable, pValue, size);
         size++; // Add in the null terminator
     }
@@ -540,7 +540,7 @@ HRESULT FusionBind::SetupFusionContext(L
     LPCWSTR pBase;
     // if the appbase is null then use the current directory
     if (szAppBase == NULL) {
-        pBase = (LPCWSTR) _alloca(_MAX_PATH * sizeof(WCHAR));
+        pBase = (LPCWSTR) Alloca(_MAX_PATH * sizeof(WCHAR));
         if(!WszGetCurrentDirectory(_MAX_PATH, (LPWSTR) pBase))
             IfFailGo(HRESULT_FROM_GetLastError());
     }
