$NetBSD$

--- src/vm/stringliteralmap.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/stringliteralmap.cpp
@@ -448,7 +448,7 @@ static void LogStringLiteral(__in_z cons
 
     int length = pStringData->GetCharCount();
     length = min(length, 100);
-    WCHAR *szString = (WCHAR *)_alloca((length + 1) * sizeof(WCHAR));
+    WCHAR *szString = (WCHAR *)Alloca((length + 1) * sizeof(WCHAR));
     memcpyNoGCRefs((void*)szString, (void*)pStringData->GetStringBuffer(), length * sizeof(WCHAR));
     szString[length] = '\0';
     LOG((LF_APPDOMAIN, LL_INFO10000, "String literal \"%S\" %s to Global map, size %d bytes\n", szString, action, pStringData->GetCharCount()));
