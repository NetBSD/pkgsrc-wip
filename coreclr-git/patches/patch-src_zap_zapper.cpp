$NetBSD$

--- src/zap/zapper.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/zap/zapper.cpp
@@ -1711,10 +1711,10 @@ IAssemblyName *Zapper::GetAssemblyFusion
                                           &md,
                                           NULL));
 
-    szName = (LPWSTR) _alloca(cbName * sizeof(WCHAR));
-    md.szLocale = (LPWSTR) _alloca(md.cbLocale * sizeof(WCHAR));
-    md.rProcessor = (DWORD *) _alloca(md.ulProcessor * sizeof(DWORD));
-    md.rOS = (OSINFO *) _alloca(md.ulOS * sizeof(OSINFO));
+    szName = (LPWSTR) Alloca(cbName * sizeof(WCHAR));
+    md.szLocale = (LPWSTR) Alloca(md.cbLocale * sizeof(WCHAR));
+    md.rProcessor = (DWORD *) Alloca(md.ulProcessor * sizeof(DWORD));
+    md.rOS = (OSINFO *) Alloca(md.ulOS * sizeof(OSINFO));
 
     IfFailThrow(pImport->GetAssemblyProps(a,
                                           &pbPublicKeyToken, &cbPublicKeyToken, NULL,
@@ -1788,10 +1788,10 @@ IAssemblyName *Zapper::GetAssemblyRefFus
                                              NULL, NULL,
                                              NULL));
 
-    szName = (LPWSTR) _alloca(cbName * sizeof(WCHAR));
-    md.szLocale = (LPWSTR) _alloca(md.cbLocale * sizeof(WCHAR));
-    md.rProcessor = (DWORD *) _alloca(md.ulProcessor * sizeof(DWORD));
-    md.rOS = (OSINFO *) _alloca(md.ulOS * sizeof(OSINFO));
+    szName = (LPWSTR) Alloca(cbName * sizeof(WCHAR));
+    md.szLocale = (LPWSTR) Alloca(md.cbLocale * sizeof(WCHAR));
+    md.rProcessor = (DWORD *) Alloca(md.ulProcessor * sizeof(DWORD));
+    md.rOS = (OSINFO *) Alloca(md.ulOS * sizeof(OSINFO));
 
     IfFailThrow(pImport->GetAssemblyRefProps(ar,
                                              &pbPublicKeyOrToken, &cbPublicKeyOrToken,
