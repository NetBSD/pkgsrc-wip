$NetBSD$

--- src/vm/clsload.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/clsload.cpp
@@ -1688,7 +1688,7 @@ ClassLoader::FindClassModuleThrowing(
                 return FALSE;
             }
 
-            pszLowerNameSpace = (LPUTF8)_alloca(allocLen);
+            pszLowerNameSpace = (LPUTF8)Alloca(allocLen);
             if (allocLen == 1)
             {
                 *pszLowerNameSpace = '\0';
@@ -1709,7 +1709,7 @@ ClassLoader::FindClassModuleThrowing(
             return FALSE;
         }
 
-        pszLowerClassName = (LPUTF8)_alloca(allocLen);
+        pszLowerClassName = (LPUTF8)Alloca(allocLen);
         if (!InternalCasingHelper::InvariantToLower(
                 pszLowerClassName, 
                 allocLen, 
