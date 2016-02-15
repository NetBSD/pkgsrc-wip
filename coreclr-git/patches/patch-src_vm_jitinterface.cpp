$NetBSD$

--- src/vm/jitinterface.cpp.orig	2016-02-06 19:16:53.000000000 +0000
+++ src/vm/jitinterface.cpp
@@ -13280,7 +13280,7 @@ BOOL TypeLayoutCheck(MethodTable * pMT, 
             size_t cbGCRefMap = (dwActualSize / sizeof(TADDR) + 7) / 8;
             _ASSERTE(cbGCRefMap > 0);
 
-            BYTE * pGCRefMap = (BYTE *)_alloca(cbGCRefMap);
+            BYTE * pGCRefMap = (BYTE *)Alloca(cbGCRefMap);
 
             ComputeGCRefMap(pMT, pGCRefMap, cbGCRefMap);
 
