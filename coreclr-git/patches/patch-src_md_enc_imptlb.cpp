$NetBSD$

--- src/md/enc/imptlb.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/md/enc/imptlb.cpp
@@ -703,7 +703,7 @@ HRESULT CImportTlb::GetAttrType(
 
                 // Build the sig.
                 dwMaxSigSize = 5 + sizeof(mdTypeRef) * 2;
-                pSig = (COR_SIGNATURE*)_alloca(dwMaxSigSize);
+                pSig = (COR_SIGNATURE*)Alloca(dwMaxSigSize);
                 pCurr = pSig;
                 *pCurr++ = IMAGE_CEE_CS_CALLCONV_DEFAULT_HASTHIS;
                 *pCurr++ = 2;
@@ -728,7 +728,7 @@ HRESULT CImportTlb::GetAttrType(
 
                 // Build the sig.
                 dwMaxSigSize = 4 + sizeof(mdTypeRef);
-                pSig = (COR_SIGNATURE*)_alloca(dwMaxSigSize);
+                pSig = (COR_SIGNATURE*)Alloca(dwMaxSigSize);
                 pCurr = pSig;
                 *pCurr++ = IMAGE_CEE_CS_CALLCONV_DEFAULT_HASTHIS;
                 *pCurr++ = 1;
@@ -3301,7 +3301,7 @@ HRESULT CImportTlb::_ConvFunction(
 
     //-------------------------------------------------------------------------
     // Get the parameter names.
-    rszParamNames = reinterpret_cast<BSTR*>(_alloca((psFunc->cParams+1) * sizeof(BSTR*)));
+    rszParamNames = reinterpret_cast<BSTR*>(Alloca((psFunc->cParams+1) * sizeof(BSTR*)));
 
     // Get list of names.
     IfFailGo(pITI->GetNames(psFunc->memid, rszParamNames, psFunc->cParams+1, &iNames));
@@ -6149,7 +6149,7 @@ HRESULT CImportTlb::_ConvSignature(     
                     {
                         // Convert the UTF8 string to unicode.
                         int MngTypeNameStrLen = (int)(strlen(pConvertionInfo->m_strMngTypeName) + 1);
-                        WCHAR *strFullyQualifiedMngTypeName = (WCHAR *)_alloca(MngTypeNameStrLen * sizeof(WCHAR));
+                        WCHAR *strFullyQualifiedMngTypeName = (WCHAR *)Alloca(MngTypeNameStrLen * sizeof(WCHAR));
                         int ret = WszMultiByteToWideChar(CP_UTF8, 0, pConvertionInfo->m_strMngTypeName, MngTypeNameStrLen, strFullyQualifiedMngTypeName, MngTypeNameStrLen);
                         _ASSERTE(ret != 0);
                         if (!ret)
@@ -6184,7 +6184,7 @@ HRESULT CImportTlb::_ConvSignature(     
         {
             // Convert the UTF8 string to unicode.
             int MngTypeNameStrLen = (int)(strlen(pConvertionInfo->m_strMngTypeName) + 1);
-            WCHAR *strFullyQualifiedMngTypeName = (WCHAR *)_alloca(MngTypeNameStrLen * sizeof(WCHAR));
+            WCHAR *strFullyQualifiedMngTypeName = (WCHAR *)Alloca(MngTypeNameStrLen * sizeof(WCHAR));
             int ret = WszMultiByteToWideChar(CP_UTF8, 0, pConvertionInfo->m_strMngTypeName, MngTypeNameStrLen, strFullyQualifiedMngTypeName, MngTypeNameStrLen);
             _ASSERTE(ret != 0);
             if (!ret)
