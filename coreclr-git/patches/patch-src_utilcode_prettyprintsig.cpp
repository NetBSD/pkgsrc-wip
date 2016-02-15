$NetBSD$

--- src/utilcode/prettyprintsig.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/utilcode/prettyprintsig.cpp
@@ -315,7 +315,7 @@ static PCCOR_SIGNATURE PrettyPrintType(
             else 
             {
                 _ASSERTE(rank != 0);
-                int* lowerBounds = (int*) _alloca(sizeof(int)*2*rank);
+                int* lowerBounds = (int*) Alloca(sizeof(int)*2*rank);
                 int* sizes               = &lowerBounds[rank];
                 memset(lowerBounds, 0, sizeof(int)*2*rank); 
                 
@@ -752,7 +752,7 @@ static HRESULT PrettyPrintTypeA(
             else 
             {
                 _ASSERTE(rank != 0);
-                int* lowerBounds = (int*) _alloca(sizeof(int)*2*rank);
+                int* lowerBounds = (int*) Alloca(sizeof(int)*2*rank);
                 int* sizes       = &lowerBounds[rank];
                 memset(lowerBounds, 0, sizeof(int)*2*rank); 
                 
