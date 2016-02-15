$NetBSD$

--- src/jit/compiler.cpp.orig	2016-02-13 00:18:27.000000000 +0000
+++ src/jit/compiler.cpp
@@ -6974,7 +6974,7 @@ void dumpConvertedVarSet(Compiler* comp,
     BYTE* pVarNumSet;   // trivial set: one byte per varNum, 0 means not in set, 1 means in set.
 
     size_t varNumSetBytes = comp->lvaCount * sizeof(BYTE);
-    pVarNumSet = (BYTE*)_alloca(varNumSetBytes);
+    pVarNumSet = (BYTE*)Alloca(varNumSetBytes);
     memset(pVarNumSet, 0, varNumSetBytes);          // empty the set
 
     VARSET_ITER_INIT(comp, iter, vars, varIndex);
