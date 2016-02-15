$NetBSD$

--- src/vm/baseassemblyspec.inl.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/baseassemblyspec.inl
@@ -559,7 +559,7 @@ inline HRESULT BaseAssemblySpec::Init(md
                                             NULL));       // [OUT] Flags.
 
         // Get the assembly name other naming properties
-        wszAssemblyName = (LPWSTR)_alloca(cchName * sizeof(WCHAR));
+        wszAssemblyName = (LPWSTR)Alloca(cchName * sizeof(WCHAR));
         IfFailRet(pImport->GetAssemblyProps(tkAssemblyRef,
                                             (const void **)&m_pbPublicKeyOrToken,
                                             &m_cbPublicKeyOrToken,
@@ -585,7 +585,7 @@ inline HRESULT BaseAssemblySpec::Init(md
                                             NULL));       // [OUT] Flags.
 
         // Get the assembly name other naming properties
-        wszAssemblyName = (LPWSTR)_alloca(cchName * sizeof(WCHAR));
+        wszAssemblyName = (LPWSTR)Alloca(cchName * sizeof(WCHAR));
         IfFailRet(pImport->GetAssemblyRefProps(tkAssemblyRef,
                                             (const void **)&m_pbPublicKeyOrToken,
                                             &m_cbPublicKeyOrToken,
