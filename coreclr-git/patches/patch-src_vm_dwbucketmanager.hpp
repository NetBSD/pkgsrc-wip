$NetBSD$

--- src/vm/dwbucketmanager.hpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/dwbucketmanager.hpp
@@ -596,7 +596,7 @@ void BaseBucketParamsManager::GetModuleN
         if (pModule->IsManifest())
         {
             // Single-module assembly; allocate a buffer and convert assembly name.
-            fullName = reinterpret_cast< WCHAR* >(_alloca(sizeof(WCHAR)*(fullNameLength)));
+            fullName = reinterpret_cast< WCHAR* >(Alloca(sizeof(WCHAR)*(fullNameLength)));
             WszMultiByteToWideChar(CP_UTF8, 0, utf8AssemblyName, -1, fullName, fullNameLength);
         }
         else
@@ -624,7 +624,7 @@ void BaseBucketParamsManager::GetModuleN
                 }
                 else
                 {
-                    fullName = reinterpret_cast< WCHAR* >(_alloca(AllocLen));
+                    fullName = reinterpret_cast< WCHAR* >(Alloca(AllocLen));
 
                     // Convert the assembly name.
                     WszMultiByteToWideChar(CP_UTF8, 0, utf8AssemblyName, -1, fullName, assemblyNameLength);
