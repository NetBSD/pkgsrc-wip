$NetBSD$

--- src/vm/comdynamic.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/comdynamic.cpp
@@ -1415,7 +1415,7 @@ HRESULT COMDynamicWrite::EmitDebugInfoBe
         if (debugDirDataSize > 0)
         {
             // Make some room for the data.
-            debugDirData = (BYTE*)_alloca(debugDirDataSize);
+            debugDirData = (BYTE*)Alloca(debugDirDataSize);
 
             // Actually get the data now.
             IfFailGo(pWriter->GetDebugInfo(&debugDirIDD,
@@ -1544,7 +1544,7 @@ HRESULT COMDynamicWrite::EmitDebugInfoEn
         SIZE_T dotOffset = dot ? dot - filename : fnLen;
 
         size_t len = dotOffset + 6;
-            WCHAR *fn = (WCHAR*)_alloca(len * sizeof(WCHAR));
+            WCHAR *fn = (WCHAR*)Alloca(len * sizeof(WCHAR));
         wcsncpy_s(fn, len, filename, dotOffset);
 
         fn[dotOffset] = W('.');
