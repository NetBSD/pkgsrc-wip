$NetBSD$

--- src/inc/winwrap.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/inc/winwrap.h
@@ -1013,11 +1013,11 @@ inline int LateboundMessageBoxA(HWND hWn
         lpCaption = "<null>";
 
     SIZE_T cchText = strlen(lpText) + 1;
-    LPWSTR wszText = (LPWSTR)_alloca(cchText * sizeof(WCHAR));
+    LPWSTR wszText = (LPWSTR)Alloca(cchText * sizeof(WCHAR));
     swprintf_s(wszText, cchText, W("%S"), lpText);
 
     SIZE_T cchCaption = strlen(lpCaption) + 1;
-    LPWSTR wszCaption = (LPWSTR)_alloca(cchCaption * sizeof(WCHAR));
+    LPWSTR wszCaption = (LPWSTR)Alloca(cchCaption * sizeof(WCHAR));
     swprintf_s(wszCaption, cchCaption, W("%S"), lpCaption);
 
     return LateboundMessageBoxW(hWnd, wszText, wszCaption, uType);
