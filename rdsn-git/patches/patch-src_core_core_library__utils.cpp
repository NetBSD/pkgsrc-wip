$NetBSD$

--- src/core/core/library_utils.cpp.orig	2016-02-27 19:59:48.000000000 +0000
+++ src/core/core/library_utils.cpp
@@ -48,6 +48,8 @@
 # elif defined(__APPLE__)
 # include <pthread.h>
 # include <dlfcn.h> 
+# elif defined(__NetBSD__)
+# include <dlfcn.h> 
 # endif
 
 # ifdef __TITLE__
@@ -69,7 +71,7 @@ namespace dsn {
             {
                 derror("load dynamic library '%s' failed, err = %d", module_name.c_str(), ::GetLastError());
             }            
-# elif defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
+# elif defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
             module_name = "lib" + module_name + ".so";
             auto hmod = dlopen(module_name.c_str(), RTLD_LAZY|RTLD_GLOBAL);
             if (nullptr == hmod)
@@ -86,7 +88,7 @@ namespace dsn {
         {
 # if defined(_WIN32)
             return (dsn_handle_t)::GetProcAddress((HMODULE)hmodule, (LPCSTR)symbol);
-# elif defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
+# elif defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
             return (dsn_handle_t)dlsym((void*)hmodule, symbol);
 # else
 # error not implemented yet
@@ -97,7 +99,7 @@ namespace dsn {
         {
 # if defined(_WIN32)
             ::CloseHandle((HMODULE)hmodule);
-# elif defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
+# elif defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
             dlclose((void*)hmodule);
 # else
 # error not implemented yet
@@ -105,4 +107,3 @@ namespace dsn {
         }
     }
 }
-
