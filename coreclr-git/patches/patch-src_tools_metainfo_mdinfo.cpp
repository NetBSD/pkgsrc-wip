$NetBSD$

--- src/tools/metainfo/mdinfo.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/tools/metainfo/mdinfo.cpp
@@ -3326,7 +3326,7 @@ HRESULT _FillVariant(
             V_VT(pvar) = VT_BSTR;
             WCHAR *TempString;;
 #if BIGENDIAN
-            TempString = (WCHAR *)alloca(cbValue);
+            TempString = (WCHAR *)Alloca(cbValue);
             memcpy(TempString, pValue, cbValue);
             SwapStringLength(TempString, cbValue/sizeof(WCHAR));
 #else
