$NetBSD: patch-krita_plugins_formats_xcf_xcftools.h,v 1.1 2013/12/07 13:17:14 nsloss Exp $

arpa/inet.h needs to be included for socklen_t definition on NetBSD.

--- krita/plugins/formats/xcf/xcftools.h.orig	2013-08-19 16:38:18.000000000 +0000
+++ krita/plugins/formats/xcf/xcftools.h
@@ -60,7 +60,10 @@ typedef signed long int   int32_t ;
 # define __ATTRIBUTE__(x)
 #endif
 
-#if HAVE_NETINET_IN_H
+#if defined(__NetBSD__)
+# include <netinet/in.h>
+# include <arpa/inet.h>
+#elif HAVE_NETINET_IN_H
 # include <netinet/in.h>
 #elif HAVE_ARPA_INET_H
 # include <arpa/inet.h>
