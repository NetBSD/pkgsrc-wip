$NetBSD$

--- src/inc/nsutilpriv.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/inc/nsutilpriv.h
@@ -223,14 +223,14 @@ void MakeNestedTypeName(                
 #define MAKE_FULL_PATH_ON_STACK_UTF8(toptr, pnamespace, pname) \
 { \
     int __i##toptr = ns::GetFullLength(pnamespace, pname); \
-    toptr = (char *) alloca(__i##toptr); \
+    toptr = (char *) Alloca(__i##toptr); \
     ns::MakePath(toptr, __i##toptr, pnamespace, pname); \
 }
 
 #define MAKE_FULL_PATH_ON_STACK_UNICODE(toptr, pnamespace, pname) \
 { \
     int __i##toptr = ns::GetFullLength(pnamespace, pname); \
-    toptr = (WCHAR *) alloca(__i##toptr * sizeof(WCHAR)); \
+    toptr = (WCHAR *) Alloca(__i##toptr * sizeof(WCHAR)); \
     ns::MakePath(toptr, __i##toptr, pnamespace, pname); \
 }
 
@@ -242,7 +242,7 @@ void MakeNestedTypeName(                
     __i##ptr += (pszMemberName ? (int) strlen(pszMemberName) : 0); \
     __i##ptr += (NAMESPACE_SEPARATOR_LEN * 2); \
     __i##ptr += (pszSig ? (int) strlen(pszSig) : 0); \
-    ptr = (LPUTF8) alloca(__i##ptr); \
+    ptr = (LPUTF8) Alloca(__i##ptr); \
     ns::MakePath(ptr, __i##ptr, pszNameSpace, pszClassName); \
     if (pszMemberName) { \
         strcat_s(ptr, __i##ptr, NAMESPACE_SEPARATOR_STR); \
