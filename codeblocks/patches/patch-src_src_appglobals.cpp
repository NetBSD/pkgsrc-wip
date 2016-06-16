$NetBSD$

--- src/src/appglobals.cpp.orig	2016-01-23 16:43:03.000000000 +0000
+++ src/src/appglobals.cpp
@@ -49,6 +49,8 @@ namespace appglobals
     const wxString AppPlatform           = _T("Darwin");
 #elif defined(__FreeBSD__)
     const wxString AppPlatform           = _T("FreeBSD");
+#elif defined(__NetBSD__)
+    const wxString AppPlatform           = _T("NetBSD");
 #elif defined(__UNIX__)
     const wxString AppPlatform           = _T("Linux");
 #else
