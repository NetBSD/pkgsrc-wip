$NetBSD$

Support NetBSD.

--- components/files/linuxpath.cpp.orig	2017-11-15 17:20:40.000000000 +0000
+++ components/files/linuxpath.cpp
@@ -1,6 +1,6 @@
 #include "linuxpath.hpp"
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__NetBSD__)
 
 #include <pwd.h>
 #include <unistd.h>
