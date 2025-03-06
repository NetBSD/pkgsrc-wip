$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -85,7 +85,7 @@ void RegionalCapabilitiesService::Initia
       base::UmaHistogramEnumeration(kUnknownCountryIdStored,
                                     UnknownCountryIdStored::kValidCountryId);
     } else {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (base::FeatureList::IsEnabled(switches::kClearPrefForUnknownCountry)) {
         profile_prefs_->ClearPref(country_codes::kCountryIDAtInstall);
         country_id.reset();
