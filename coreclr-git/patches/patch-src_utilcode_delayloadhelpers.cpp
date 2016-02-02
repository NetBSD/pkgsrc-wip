$NetBSD$

--- src/utilcode/delayloadhelpers.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/utilcode/delayloadhelpers.cpp
@@ -93,7 +93,7 @@ namespace DelayLoad
             HMODULE hMod = nullptr;
             IfFailRet(m_pModule->GetValue(&hMod));
 
-            LPVOID pvFunc = ::GetProcAddress(hMod, m_szFunctionName);
+            LPVOID pvFunc = reinterpret_cast<LPVOID>(::GetProcAddress(hMod, m_szFunctionName));
             hr = (pvFunc == nullptr) ? HRESULT_FROM_GetLastError() : S_OK;
             
             {   // Lock scope
@@ -112,4 +112,3 @@ namespace DelayLoad
         return m_hr;
     }
 }
-
