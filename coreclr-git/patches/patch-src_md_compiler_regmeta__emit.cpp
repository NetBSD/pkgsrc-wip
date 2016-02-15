$NetBSD$

--- src/md/compiler/regmeta_emit.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/md/compiler/regmeta_emit.cpp
@@ -1689,7 +1689,7 @@ HRESULT RegMeta::_DefineSetConstant(    
         {
 #if BIGENDIAN
             void *pValueTemp;
-            pValueTemp = (void *)alloca(cbBlob);
+            pValueTemp = (void *)Alloca(cbBlob);
             IfFailGo(m_pStgdb->m_MiniMd.SwapConstant(pValue, dwCPlusTypeFlag, pValueTemp, cbBlob));
             pValue = pValueTemp;
 #endif
