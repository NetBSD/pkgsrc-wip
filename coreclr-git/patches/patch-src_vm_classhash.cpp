$NetBSD$

--- src/vm/classhash.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/classhash.cpp
@@ -306,7 +306,7 @@ VOID EEClassHashTable::ConstructKeyFromD
             INT32 iAllocSize;
             if (!ClrSafeInt<INT32>::addition(iNSLength, iNameLength, iAllocSize))
                 COMPlusThrowOM();
-            LPUTF8 pszOutNameSpace = (LPUTF8) _alloca(iAllocSize);
+            LPUTF8 pszOutNameSpace = (LPUTF8) Alloca(iAllocSize);
             if (iNSLength == 1)
             {
                 *pszOutNameSpace = '\0';
