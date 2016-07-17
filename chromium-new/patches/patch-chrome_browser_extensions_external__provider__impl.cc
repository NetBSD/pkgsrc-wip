$NetBSD$

--- chrome/browser/extensions/external_provider_impl.cc.orig	2016-06-24 01:02:12.000000000 +0000
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -646,7 +646,7 @@ void ExternalProviderImpl::CreateExterna
                                  Manifest::EXTERNAL_PREF_DOWNLOAD,
                                  oem_extension_creation_flags)));
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!profile->IsLegacySupervised()) {
     provider_list->push_back(
         linked_ptr<ExternalProviderInterface>(
@@ -688,7 +688,7 @@ void ExternalProviderImpl::CreateExterna
                 bundled_extension_creation_flags)));
 
     // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD))
     provider_list->push_back(
         linked_ptr<ExternalProviderInterface>(
             new ExternalProviderImpl(
