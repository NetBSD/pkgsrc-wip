$NetBSD$

--- src/vm/dllimport.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/dllimport.cpp
@@ -3668,7 +3668,7 @@ BOOL NDirect::MarshalingRequired(MethodD
     numArgs++;   // +1 for return type
 
     // We'll need to parse parameter native types
-    mdParamDef *pParamTokenArray = (mdParamDef *)_alloca(numArgs * sizeof(mdParamDef));
+    mdParamDef *pParamTokenArray = (mdParamDef *)Alloca(numArgs * sizeof(mdParamDef));
     IMDInternalImport *pMDImport = pModule->GetMDImport();
 
     SigTypeContext emptyTypeContext;
@@ -5511,7 +5511,7 @@ MethodDesc* NDirect::CreateCLRToNativeIL
     
     Module *pModule = pSigDesc->m_pModule;
     numParamTokens = numArgs + 1;
-    pParamTokenArray = (mdParamDef*)_alloca(numParamTokens * sizeof(mdParamDef));
+    pParamTokenArray = (mdParamDef*)Alloca(numParamTokens * sizeof(mdParamDef));
     CollateParamTokens(pModule->GetMDImport(), pSigDesc->m_tkMethodDef, numArgs, pParamTokenArray);
 
     // for interop vectors that have declarative security, we need
@@ -5615,7 +5615,7 @@ MethodDesc* NDirect::CreateFieldAccessIL
     int numParamTokens = numArgs + 1;
 
     // make sure we capture marshaling metadata
-    mdParamDef* pParamTokenArray = (mdParamDef *)_alloca(numParamTokens * sizeof(mdParamDef));
+    mdParamDef* pParamTokenArray = (mdParamDef *)Alloca(numParamTokens * sizeof(mdParamDef));
     pParamTokenArray[0] = mdParamDefNil;
     pParamTokenArray[numArgs] = (mdParamDef)fd;
 
@@ -6102,7 +6102,7 @@ void CreateCLRToDispatchCOMStub(
                                     &numArgs);
 
     numParamTokens = numArgs + 1;
-    pParamTokenArray = (mdParamDef*)_alloca(numParamTokens * sizeof(mdParamDef));
+    pParamTokenArray = (mdParamDef*)Alloca(numParamTokens * sizeof(mdParamDef));
     CollateParamTokens(sigDesc.m_pModule->GetMDImport(), sigDesc.m_tkMethodDef, numArgs, pParamTokenArray);
 
     DispatchStubState MyStubState;
