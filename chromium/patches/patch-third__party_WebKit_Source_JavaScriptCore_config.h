$NetBSD: patch-third__party_WebKit_Source_JavaScriptCore_config.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/JavaScriptCore/config.h.orig	2011-04-13 08:12:07.000000000 +0000
+++ third_party/WebKit/Source/JavaScriptCore/config.h
@@ -57,7 +57,7 @@
 
 #endif
 
-#if OS(FREEBSD) || OS(OPENBSD)
+#if OS(BSD)
 #define HAVE_PTHREAD_NP_H 1
 #endif
 
