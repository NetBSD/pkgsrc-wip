$NetBSD$

--- src/jit/flowgraph.cpp.orig	2016-02-09 22:37:14.000000000 +0000
+++ src/jit/flowgraph.cpp
@@ -19235,7 +19235,7 @@ ONE_FILE_PER_METHOD:;
         {
             wCharCount += wcslen(pathname) + 1;
         }
-        filename = (LPCWSTR) alloca(wCharCount * sizeof(WCHAR));
+        filename = (LPCWSTR) Alloca(wCharCount * sizeof(WCHAR));
         if (pathname != NULL)
         {
             swprintf_s((LPWSTR)filename, wCharCount, W("%s\\%S-%s.%s"), pathname, escapedString, phaseName, type);
@@ -19297,7 +19297,7 @@ ONE_FILE_PER_METHOD:;
         {
             wCharCount += wcslen(pathname) + 1;
         }
-        filename = (LPCWSTR) alloca(wCharCount * sizeof(WCHAR));
+        filename = (LPCWSTR) Alloca(wCharCount * sizeof(WCHAR));
         if (pathname != NULL)
         {
             swprintf_s((LPWSTR)filename, wCharCount, W("%s\\%s.%s"), pathname, origFilename, type);
