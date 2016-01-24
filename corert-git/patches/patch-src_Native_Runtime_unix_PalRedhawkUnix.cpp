$NetBSD$

--- src/Native/Runtime/unix/PalRedhawkUnix.cpp.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/Runtime/unix/PalRedhawkUnix.cpp
@@ -33,6 +33,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/time.h>
+#include <cstdarg>
 
 #if !HAVE_SYSCONF && !HAVE_SYSCTL
 #error Neither sysconf nor sysctl is present on the current system
