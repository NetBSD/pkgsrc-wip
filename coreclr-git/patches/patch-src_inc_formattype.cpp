$NetBSD$

--- src/inc/formattype.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/inc/formattype.cpp
@@ -564,7 +564,7 @@ PCCOR_SIGNATURE PrettyPrintType(
 #pragma prefast(push)
 #pragma prefast(disable:22009 "Suppress PREFAST warnings about integer overflow")
 #endif
-                    int* lowerBounds = (int*) _alloca(sizeof(int)*2*rank);
+                    int* lowerBounds = (int*) Alloca(sizeof(int)*2*rank);
                     int* sizes       = &lowerBounds[rank];  
                     memset(lowerBounds, 0, sizeof(int)*2*rank); 
                     
@@ -1204,7 +1204,7 @@ char* DumpMarshaling(IMDInternalImport* 
 #pragma prefast(push)
 #pragma prefast(disable:22009 "Suppress PREFAST warnings about integer overflow")
 #endif
-                            strTemp = (LPUTF8)_alloca(strLen + 1);
+                            strTemp = (LPUTF8)Alloca(strLen + 1);
                             memcpy(strTemp, (LPUTF8)&pSigNativeType[cbCur], strLen);
                             strTemp[strLen] = 0;
                             buf.AppendPrintf(", \"%s\"", UnquotedProperName(strTemp));
