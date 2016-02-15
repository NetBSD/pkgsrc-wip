$NetBSD$

--- src/inc/corperme.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/inc/corperme.h
@@ -38,14 +38,14 @@ extern "C" {
 #define WIDEN(psz, pwsz) \
     LPCSTR _##psz = (LPCSTR) psz; \
     int _cc##psz = _##psz ? strlen(_##psz) + 1 : 0; \
-    LPWSTR pwsz = (LPWSTR) (_cc##psz ? _alloca((_cc##psz) * sizeof(WCHAR)) : NULL); \
+    LPWSTR pwsz = (LPWSTR) (_cc##psz ? Alloca((_cc##psz) * sizeof(WCHAR)) : NULL); \
     if(pwsz) WszMultiByteToWideChar(WIDEN_CP, 0, _##psz, _cc##psz, pwsz, _cc##psz);
 
 
 #define NARROW(pwsz, psz) \
     LPCWSTR _##pwsz = (LPCWSTR) pwsz; \
     int _cc##psz =  _##pwsz ? WszWideCharToMultiByte(WIDEN_CP, 0, _##pwsz, -1, NULL, 0, NULL, NULL) : 0; \
-    LPSTR psz = (LPSTR) (_cc##psz ? _alloca(_cc##psz) : NULL); \
+    LPSTR psz = (LPSTR) (_cc##psz ? Alloca(_cc##psz) : NULL); \
     if(psz) WszWideCharToMultiByte(WIDEN_CP, 0, _##pwsz, -1, psz, _cc##psz, NULL, NULL);
 
 
