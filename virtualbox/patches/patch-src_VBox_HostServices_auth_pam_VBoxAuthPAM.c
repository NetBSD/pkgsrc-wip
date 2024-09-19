$NetBSD$

--- src/VBox/HostServices/auth/pam/VBoxAuthPAM.c.orig	2016-03-04 19:29:32.000000000 +0000
+++ src/VBox/HostServices/auth/pam/VBoxAuthPAM.c
@@ -74,7 +74,7 @@
 #include <stdlib.h>
 #include <stdarg.h>
 #include <string.h>
-#ifndef RT_OS_FREEBSD
+#if !defined(RT_OS_FREEBSD) && !defied(RT_OS_NETBSD)
 # include <malloc.h>
 #endif
 
