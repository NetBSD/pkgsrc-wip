$NetBSD$

--- fpx/f_fpxvw.cpp.orig	2015-12-28 09:55:50.000000000 +0000
+++ fpx/f_fpxvw.cpp
@@ -664,7 +664,7 @@ Boolean PFileFlashPixView::CreateCompObj
       lpszNew[0]=chZero;
     }
 
-#if defined(macintosh) || defined(__unix)
+#if defined(macintosh) || defined(_UNIX)
     curCompObj->WriteVT_LPSTR_NoPad(lpszNew);
 #elif _WINDOWS
     char str[1024];
@@ -675,7 +675,7 @@ Boolean PFileFlashPixView::CreateCompObj
     // Get and write clsID string
     LPOLESTR FAR clsIDStr;
     StringFromCLSID(clsID, &clsIDStr);
-#if defined(macintosh) || defined(__unix)
+#if defined(macintosh) || defined(_UNIX)
     curCompObj->WriteVT_LPSTR_NoPad(clsIDStr);
 #elif _WINDOWS
     WideCharToMultiByte(CP_ACP, 0, clsIDStr, -1, str, 128, NULL, NULL);
@@ -683,7 +683,7 @@ Boolean PFileFlashPixView::CreateCompObj
 #endif
 
     // Write prog id ( for now just write length = 0 )
-#if defined(macintosh) || defined(__unix)
+#if defined(macintosh) || defined(_UNIX)
     curCompObj->WriteVT_LPSTR_NoPad(&chZero);
 #elif _WINDOWS
     char progID = 0;
@@ -695,21 +695,21 @@ Boolean PFileFlashPixView::CreateCompObj
     curCompObj->WriteVT_I4(&temp);
 
     // Write unicode user type ( for now just write length = 0 )
-#if defined(macintosh) || defined(__unix)
+#if defined(macintosh) || defined(_UNIX)
     curCompObj->WriteVT_LPWSTR_NoPad(MultiByteToWideChar(lpszNew));
 #elif _WINDOWS
     curCompObj->WriteVT_LPWSTR_NoPad(lpszNew);
 #endif
 
     // Write unicode clipboard format
-#if defined(macintosh) || defined(__unix)
+#if defined(macintosh) || defined(_UNIX)
     curCompObj->WriteVT_LPWSTR_NoPad(MultiByteToWideChar(&chZero));
 #elif _WINDOWS
     curCompObj->WriteVT_LPWSTR_NoPad(&chZero);
 #endif
 
     // Write unicode prog id ( for now just write length = 0 )
-#if defined(macintosh) || defined(__unix)
+#if defined(macintosh) || defined(_UNIX)
     curCompObj->WriteVT_LPWSTR_NoPad(MultiByteToWideChar(&chZero));
 #elif _WINDOWS
     curCompObj->WriteVT_LPWSTR_NoPad(&chZero);
