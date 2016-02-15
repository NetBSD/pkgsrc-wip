$NetBSD$

--- src/vm/clrtocomcall.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/clrtocomcall.cpp
@@ -518,7 +518,7 @@ I4ARRAYREF SetUpWrapperInfo(MethodDesc *
 
         // Collects ParamDef information in an indexed array where element 0 represents
         // the return type.
-        mdParamDef *params = (mdParamDef*)_alloca((numArgs+1) * sizeof(mdParamDef));
+        mdParamDef *params = (mdParamDef*)Alloca((numArgs+1) * sizeof(mdParamDef));
         CollateParamTokens(msig.GetModule()->GetMDImport(), pMD->GetMemberDef(), numArgs, params);
 
 
@@ -728,7 +728,7 @@ UINT32 CLRToCOMLateBoundWorker(ComPlusMe
                 if (allocSize < cAssoc)
                     COMPlusThrow(kTypeLoadException, IDS_EE_TOOMANYASSOCIATES);
                 
-                pAssoc = (ASSOCIATE_RECORD*) _alloca((size_t) allocSize);
+                pAssoc = (ASSOCIATE_RECORD*) Alloca((size_t) allocSize);
                 IfFailThrow(pMDImport->GetAllAssociates(&henum, pAssoc, cAssoc));
                 
                 pMDImport->EnumClose(&henum);
