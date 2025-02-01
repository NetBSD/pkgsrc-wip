$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/external_provider_impl.cc.orig	2025-01-27 17:37:37.000000000 +0000
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -790,7 +790,7 @@ void ExternalProviderImpl::CreateExterna
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
   if (!profile->GetPrefs()->GetBoolean(pref_names::kBlockExternalExtensions)) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         base::MakeRefCounted<ExternalPrefLoader>(
@@ -818,7 +818,7 @@ void ExternalProviderImpl::CreateExterna
         bundled_extension_creation_flags));
 
     // Define a per-user source of external extensions.
-#if BUILDFLAG(IS_MAC) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if BUILDFLAG(IS_MAC) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
                           BUILDFLAG(CHROMIUM_BRANDING))
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
