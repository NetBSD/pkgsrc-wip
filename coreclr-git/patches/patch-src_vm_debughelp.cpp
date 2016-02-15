$NetBSD$

--- src/vm/debughelp.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/debughelp.cpp
@@ -884,7 +884,7 @@ StackWalkAction PrintStackTraceCallback(
 
     MethodDesc* pMD = pCF->GetFunction();
     const int nLen = 2048 - 1;    // keep one character for "\n"
-    wchar_t *buff = (wchar_t*)alloca((nLen + 1) * sizeof(wchar_t));
+    wchar_t *buff = (wchar_t*)Alloca((nLen + 1) * sizeof(wchar_t));
     buff[0] = 0;
     buff[nLen-1] = W('\0');                    // make sure the buffer is always NULL-terminated
 
