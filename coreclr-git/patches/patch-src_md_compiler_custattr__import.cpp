$NetBSD$

--- src/md/compiler/custattr_import.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/md/compiler/custattr_import.cpp
@@ -77,7 +77,7 @@ STDMETHODIMP RegMeta::GetCustomAttribute
     pMiniMd = &(m_pStgdb->m_MiniMd);
 
     iLen = WszWideCharToMultiByte(CP_UTF8,0, wzName,-1, NULL,0, 0,0);
-    szName = (LPUTF8)_alloca(iLen);
+    szName = (LPUTF8)Alloca(iLen);
     VERIFY(WszWideCharToMultiByte(CP_UTF8,0, wzName,-1, szName,iLen, 0,0));
 
     hr = ImportHelper::GetCustomAttributeByName(pMiniMd, tkObj, szName, ppData, pcbData);
