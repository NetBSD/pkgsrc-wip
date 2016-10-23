$NetBSD$

--- src/other/openscenegraph/src/osg/GLExtensions.cpp.orig	2016-08-09 06:51:57.000000000 +0000
+++ src/other/openscenegraph/src/osg/GLExtensions.cpp
@@ -376,7 +376,7 @@ OSG_INIT_SINGLETON_PROXY(GLExtensionDisa
         static void *handle = dlopen((const char *)0L, RTLD_LAZY);
         return dlsym(handle, funcName);
 
-    #elif defined (__FreeBSD__)
+    #elif defined (__FreeBSD__) || defined(__NetBSD__)
 
         return dlsym( RTLD_DEFAULT, funcName );
 
