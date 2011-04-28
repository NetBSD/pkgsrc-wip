$NetBSD: patch-webkit_glue_webkitclient__impl.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- webkit/glue/webkitclient_impl.cc.orig	2011-04-13 08:01:08.000000000 +0000
+++ webkit/glue/webkitclient_impl.cc
@@ -42,7 +42,7 @@
 #include "webkit/glue/websocketstreamhandle_impl.h"
 #include "webkit/glue/weburlloader_impl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "v8/include/v8.h"
 #endif
 
@@ -205,7 +205,7 @@ WebKitClientImpl::~WebKitClientImpl() {
 }
 
 WebThemeEngine* WebKitClientImpl::themeEngine() {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return &theme_engine_;
 #else
   return NULL;
