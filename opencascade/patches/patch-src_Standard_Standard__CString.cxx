$NetBSD$

--- src/Standard/Standard_CString.cxx.orig	2016-04-04 14:58:18.000000000 +0000
+++ src/Standard/Standard_CString.cxx
@@ -80,7 +80,7 @@ Standard_Integer HashCodes (const Standa
     // glibc version for android platform use locale-independent implementation of
     // strtod, strtol, strtoll functions. For other system with locale-depended
     // implementations problems may appear if "C" locale is not set explicitly.
-    #if !defined(__ANDROID__) && !defined(__QNX__) && !defined(__MINGW32__)
+    #if !defined(__ANDROID__) && !defined(__QNX__) && !defined(__MINGW32__) && !defined(__NetBSD__)
       #error System does not support xlocale. Import/export could be broken if C locale did not specified by application.
     #endif
     #define strtod_l(thePtr, theNextPtr, theLocale)              strtod(thePtr, theNextPtr)
