$NetBSD$

The BSDs all keep endian.h in /usr/include/machine.

--- nall/platform.hpp.orig	2017-05-10 15:54:49.000000000 +0000
+++ nall/platform.hpp
@@ -32,6 +32,7 @@ namespace Math {
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/param.h>
 
 #if defined(_WIN32)
   #include <io.h>
@@ -41,7 +42,7 @@ namespace Math {
   #undef interface
   #define dllexport __declspec(dllexport)
 #else
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(BSD)
   #include <machine/endian.h>
 #else
   #include <endian.h>
