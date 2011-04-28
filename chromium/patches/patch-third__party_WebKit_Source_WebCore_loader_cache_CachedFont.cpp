$NetBSD: patch-third__party_WebKit_Source_WebCore_loader_cache_CachedFont.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/loader/cache/CachedFont.cpp.orig	2011-04-13 08:12:44.000000000 +0000
+++ third_party/WebKit/Source/WebCore/loader/cache/CachedFont.cpp
@@ -27,7 +27,7 @@
 #include "config.h"
 #include "CachedFont.h"
 
-#if PLATFORM(CG) || PLATFORM(QT) || PLATFORM(GTK) || (PLATFORM(CHROMIUM) && (OS(WINDOWS) || OS(LINUX) || OS(FREEBSD))) || PLATFORM(HAIKU) || OS(WINCE) || PLATFORM(ANDROID) || PLATFORM(BREWMP)
+#if PLATFORM(CG) || PLATFORM(QT) || PLATFORM(GTK) || (PLATFORM(CHROMIUM) && (OS(WINDOWS) || OS(LINUX) || OS(BSD))) || PLATFORM(HAIKU) || OS(WINCE) || PLATFORM(ANDROID) || PLATFORM(BREWMP)
 #define STORE_FONT_CUSTOM_PLATFORM_DATA
 #endif
 
