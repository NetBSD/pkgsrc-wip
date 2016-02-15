$NetBSD$

--- src/vm/comtoclrcall.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/comtoclrcall.cpp
@@ -1556,7 +1556,7 @@ void ComCallMethodDesc::InitNativeInfo()
 
             // Collects ParamDef information in an indexed array where element 0 represents 
             // the return type.
-            mdParamDef *params = (mdParamDef*)_alloca((numArgs+1) * sizeof(mdParamDef));
+            mdParamDef *params = (mdParamDef*)Alloca((numArgs+1) * sizeof(mdParamDef));
             CollateParamTokens(pInternalImport, md, numArgs, params);
 
 #ifdef _TARGET_X86_
