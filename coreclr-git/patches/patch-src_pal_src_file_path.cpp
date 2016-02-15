$NetBSD$

--- src/pal/src/file/path.cpp.orig	2016-02-13 00:18:27.000000000 +0000
+++ src/pal/src/file/path.cpp
@@ -224,7 +224,7 @@ GetFullPathNameW(
     }
     else
     {
-        fileNameA = static_cast<LPSTR>(alloca(fileNameLength));
+        fileNameA = static_cast<LPSTR>(Alloca(fileNameLength));
     }
     
     /* Now convert lpFileName to ANSI. */
