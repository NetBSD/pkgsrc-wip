$NetBSD$

Add missing entries for NetBSD.

--- cmake/Conky.cmake.orig	2020-07-27 12:01:52.000000000 +0000
+++ cmake/Conky.cmake
@@ -55,6 +55,7 @@ endif(CMAKE_SYSTEM_NAME MATCHES "Darwin"
 
 if(NOT OS_LINUX
    AND NOT OS_FREEBSD
+   AND NOT OS_NETBSD
    AND NOT OS_OPENBSD
    AND NOT OS_DRAGONFLY
    AND NOT OS_SOLARIS
@@ -71,6 +72,9 @@ endif(NOT
       OS_FREEBSD
       AND
       NOT
+      OS_NETBSD
+      AND
+      NOT
       OS_OPENBSD
       AND
       NOT
@@ -113,6 +117,10 @@ if(OS_FREEBSD)
     )
 endif(OS_FREEBSD)
 
+if(OS_NETBSD)
+  add_definitions(-D_NETBSD_SOURCE -D_XOPEN_SOURCE=700 -D_KMEMUSER)
+endif(OS_NETBSD)
+
 if(OS_DRAGONFLY)
   set(conky_libs ${conky_libs} -L/usr/pkg/lib)
   set(conky_includes ${conky_includes} -I/usr/pkg/include)
