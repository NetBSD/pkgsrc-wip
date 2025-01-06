$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/profiles/profile_keyed_service_factory.cc.orig	2024-10-18 12:34:01.897079500 +0000
+++ chrome/browser/profiles/profile_keyed_service_factory.cc
@@ -22,6 +22,9 @@ ProfileKeyedServiceFactory::~ProfileKeye
 
 content::BrowserContext* ProfileKeyedServiceFactory::GetBrowserContextToUse(
     content::BrowserContext* context) const {
+  return context;
+#if 0
   Profile* profile = Profile::FromBrowserContext(context);
   return profile_selections_.ApplyProfileSelection(profile);
+#endif
 }
