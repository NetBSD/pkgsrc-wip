$NetBSD$

--- src/vm/method.cpp.orig	2016-02-01 23:37:48.000000000 +0000
+++ src/vm/method.cpp
@@ -5211,7 +5211,7 @@ LPVOID NDirectMethodDesc::FindEntryPoint
 
     // Allocate a single character before the start of this string to enable quickly
     // prepending a '_' character if we look for a stdcall entrypoint later on.
-    LPSTR szAnsiEntrypointName = ((LPSTR)_alloca(dstbufsize + 1)) + 1;
+    LPSTR szAnsiEntrypointName = ((LPSTR)Alloca(dstbufsize + 1)) + 1;
 
     // Copy the name so we can mangle it.
     strcpy_s(szAnsiEntrypointName,dstbufsize,GetEntrypointName());
