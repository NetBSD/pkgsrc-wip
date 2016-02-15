$NetBSD$

--- src/vm/assemblyspec.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/assemblyspec.cpp
@@ -1573,7 +1573,7 @@ HRESULT AssemblySpec::EmitToken(
             AMD.cbLocale = MultiByteToWideChar(CP_UTF8, 0, m_context.szLocale, -1, NULL, 0);
             if(AMD.cbLocale==0)
                 IfFailGo(HRESULT_FROM_GetLastError());
-            AMD.szLocale = (LPWSTR) alloca(AMD.cbLocale * sizeof(WCHAR) );
+            AMD.szLocale = (LPWSTR) Alloca(AMD.cbLocale * sizeof(WCHAR) );
             if(MultiByteToWideChar(CP_UTF8, 0, m_context.szLocale, -1, AMD.szLocale, AMD.cbLocale)==0)
                 IfFailGo(HRESULT_FROM_GetLastError());
         }
