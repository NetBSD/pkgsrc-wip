$NetBSD$

--- src/pal/src/file/directory.cpp.orig	2016-02-13 00:18:27.000000000 +0000
+++ src/pal/src/file/directory.cpp
@@ -600,7 +600,7 @@ CreateDirectoryA(
 
         // Copy cwd, '/', path
         int iLen = strlen(cwd) + 1 + pathLength + 1;
-        realPath = static_cast<char *>(alloca(iLen));
+        realPath = static_cast<char *>(Alloca(iLen));
         sprintf_s(realPath, iLen, "%s/%s", cwd, UnixPathName);
 
         PAL_free((char *)cwd);
