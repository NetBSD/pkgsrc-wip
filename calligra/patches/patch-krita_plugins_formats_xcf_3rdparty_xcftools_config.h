$NetBSD$

They don't actually generate this config.h and NetBSD has htonl() in arpa/inet.h

--- krita/plugins/formats/xcf/3rdparty/xcftools/config.h.orig	2015-11-02 13:52:02.000000000 +0000
+++ krita/plugins/formats/xcf/3rdparty/xcftools/config.h
@@ -1,4 +1,8 @@
+#ifdef __NetBSD__
+#define HAVE_ARPA_INET_H 1
+#else
 #define HAVE_NETINET_IN_H 1
+#endif
 
 #ifdef _MSC_VER
 #   if _MSC_VER < 1800
