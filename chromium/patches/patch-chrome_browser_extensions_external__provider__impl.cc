$NetBSD$

--- chrome/browser/extensions/external_provider_impl.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -760,7 +760,7 @@ void ExternalProviderImpl::CreateExterna
   }
 #endif
   if (!profile->GetPrefs()->GetBoolean(pref_names::kBlockExternalExtensions)) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         base::MakeRefCounted<ExternalPrefLoader>(
@@ -787,7 +787,7 @@ void ExternalProviderImpl::CreateExterna
           bundled_extension_creation_flags));
 
       // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && BUILDFLAG(CHROMIUM_BRANDING))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(CHROMIUM_BRANDING))
       provider_list->push_back(std::make_unique<ExternalProviderImpl>(
           service,
           base::MakeRefCounted<ExternalPrefLoader>(
