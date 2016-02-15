$NetBSD$

--- src/vm/compile.cpp.orig	2016-02-04 01:25:17.000000000 +0000
+++ src/vm/compile.cpp
@@ -2639,7 +2639,7 @@ void CEECompileInfo::EncodeTypeLayout(CO
         size_t cbGCRefMap = (dwSize / sizeof(TADDR) + 7) / 8;
         _ASSERTE(cbGCRefMap > 0);
 
-        BYTE * pGCRefMap = (BYTE *)_alloca(cbGCRefMap);
+        BYTE * pGCRefMap = (BYTE *)Alloca(cbGCRefMap);
 
         ComputeGCRefMap(pMT, pGCRefMap, cbGCRefMap);
 
