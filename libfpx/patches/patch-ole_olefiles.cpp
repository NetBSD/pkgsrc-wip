$NetBSD$
* __unix is not defined on NetBSD, _UNIX is always defined by the build system
--- ole/olefiles.cpp.orig	2013-09-02 15:45:00.000000000 +0000
+++ ole/olefiles.cpp
@@ -387,7 +387,7 @@ static OLECHAR * AsciiToOLECHAR(const ch
         if (filename == NULL)
                 return NULL;
 
-#if defined(macintosh) || defined(__unix)
+#if defined(macintosh) || defined(_UNIX)
         // find the length of filename.
         size_t len = strlen(filename);
 
