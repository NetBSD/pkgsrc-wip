$NetBSD: patch-third__party_WebKit_Source_JavaScriptCore_config.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/WebKit/Source/JavaScriptCore/config.h.orig	2011-05-24 08:03:02.000000000 +0000
+++ third_party/WebKit/Source/JavaScriptCore/config.h
@@ -61,7 +61,7 @@
 #define WTF_USE_OS_RANDOMNESS 1
 #endif
 
-#if OS(FREEBSD) || OS(OPENBSD)
+#if OS(BSD)
 #define HAVE_PTHREAD_NP_H 1
 #endif
 
