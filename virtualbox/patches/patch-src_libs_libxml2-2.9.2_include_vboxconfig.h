$NetBSD$

--- src/libs/libxml2-2.9.2/include/vboxconfig.h.orig	2016-03-04 19:30:26.000000000 +0000
+++ src/libs/libxml2-2.9.2/include/vboxconfig.h
@@ -9,7 +9,7 @@
 #undef SUPPORT_IP6
 
 /* Define if getaddrinfo is there */
-#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # define HAVE_GETADDRINFO 1
 #else
 # undef HAVE_GETADDRINFO
@@ -434,4 +434,3 @@
 /* make sure LIBXML_ICONV_ENABLED is killed */
 #include <libxml/xmlversion.h>
 #undef LIBXML_ICONV_ENABLED
-
