$NetBSD$

--- src/debug/daccess/nidump.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/debug/daccess/nidump.cpp
@@ -2380,14 +2380,14 @@ mdAssemblyRef NativeImageDumper::MapAsse
     LPWSTR szAssemblyName           = NULL;
 
     if (cchName > 0)
-        szAssemblyName = (LPWSTR) _alloca(cchName * sizeof(WCHAR));
+        szAssemblyName = (LPWSTR) Alloca(cchName * sizeof(WCHAR));
 
     if (metadata.cbLocale > 0)
-        metadata.szLocale = (LPWSTR) _alloca(metadata.cbLocale * sizeof(WCHAR));
+        metadata.szLocale = (LPWSTR) Alloca(metadata.cbLocale * sizeof(WCHAR));
     if (metadata.ulProcessor > 0)
-        metadata.rProcessor = (DWORD*) _alloca(metadata.ulProcessor * sizeof(DWORD));
+        metadata.rProcessor = (DWORD*) Alloca(metadata.ulProcessor * sizeof(DWORD));
     if (metadata.ulOS > 0)
-        metadata.rOS = (OSINFO*) _alloca(metadata.ulOS * sizeof(OSINFO));
+        metadata.rOS = (OSINFO*) Alloca(metadata.ulOS * sizeof(OSINFO));
 
     const void *pbPublicKey;
     ULONG cbPublicKey;
@@ -2876,7 +2876,7 @@ IMetaDataImport2 * NativeImageDumper::Ty
                 size_t cbLowerBounds;
                 if (!ClrSafeInt<size_t>::multiply(rank, 2*sizeof(int), cbLowerBounds/* passed by ref */))
                     ThrowHR(COR_E_OVERFLOW);
-                int* lowerBounds = (int*) _alloca(cbLowerBounds);
+                int* lowerBounds = (int*) Alloca(cbLowerBounds);
                 int* sizes       = &lowerBounds[rank];  
                 memset(lowerBounds, 0, sizeof(int)*2*rank); 
                 
