$NetBSD$

--- chrome/browser/extensions/external_provider_impl.cc.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -647,7 +647,7 @@ void ExternalProviderImpl::CreateExterna
                                  Manifest::EXTERNAL_PREF_DOWNLOAD,
                                  oem_extension_creation_flags)));
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!profile->IsLegacySupervised()) {
     provider_list->push_back(
         linked_ptr<ExternalProviderInterface>(
@@ -689,7 +689,7 @@ void ExternalProviderImpl::CreateExterna
                 bundled_extension_creation_flags)));
 
     // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD))
     provider_list->push_back(
         linked_ptr<ExternalProviderInterface>(
             new ExternalProviderImpl(
