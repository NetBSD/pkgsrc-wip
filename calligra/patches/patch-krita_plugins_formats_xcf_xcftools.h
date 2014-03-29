$NetBSD: patch-krita_plugins_formats_xcf_xcftools.h,v 1.2 2014/03/29 14:10:18 nsloss Exp $

arpa/inet.h needs to be included for socklen_t definition on NetBSD.

--- krita/plugins/formats/xcf/xcftools.h.orig	2013-10-12 08:17:59.000000000 +0000
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
