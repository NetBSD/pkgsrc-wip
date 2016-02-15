$NetBSD$

--- src/vm/baseassemblyspec.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/baseassemblyspec.cpp
@@ -498,7 +498,7 @@ HRESULT BaseAssemblySpec::Init(IAssembly
     hr = pName->GetProperty(ASM_NAME_CULTURE, NULL, &cbSize);
     
     if (hr == HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)) {
-        LPWSTR pwName = (LPWSTR) alloca(cbSize);
+        LPWSTR pwName = (LPWSTR) Alloca(cbSize);
         IfFailRet(pName->GetProperty(ASM_NAME_CULTURE, pwName, &cbSize));
 
         hr = FString::ConvertUnicode_Utf8(pwName, & ((LPSTR &) m_context.szLocale));
