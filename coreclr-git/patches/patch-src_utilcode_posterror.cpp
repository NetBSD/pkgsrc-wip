$NetBSD$

--- src/utilcode/posterror.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/utilcode/posterror.cpp
@@ -341,7 +341,7 @@ HRESULT __cdecl PostErrorVA(            
 #ifdef FEATURE_COMINTEROP        
 
     const DWORD cchMsg = 4096;
-    WCHAR      *rcMsg = (WCHAR*)alloca(cchMsg * sizeof(WCHAR));             // Error message.
+    WCHAR      *rcMsg = (WCHAR*)Alloca(cchMsg * sizeof(WCHAR));             // Error message.
     HRESULT     hr;
 
     BEGIN_ENTRYPOINT_NOTHROW;
