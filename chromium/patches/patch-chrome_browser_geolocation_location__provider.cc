$NetBSD: patch-chrome_browser_geolocation_location__provider.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/geolocation/location_provider.cc.orig	2011-04-13 08:01:43.000000000 +0000
+++ chrome/browser/geolocation/location_provider.cc
@@ -56,7 +56,7 @@ void LocationProviderBase::UpdateListene
   }
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_WIN)
+#if !defined(OS_POSIX) && !defined(OS_WIN)
 LocationProviderBase* NewSystemLocationProvider() {
   return NULL;
 }
