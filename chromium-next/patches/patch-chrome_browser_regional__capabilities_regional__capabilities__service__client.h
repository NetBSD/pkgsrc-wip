$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/regional_capabilities/regional_capabilities_service_client.h.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/regional_capabilities/regional_capabilities_service_client.h
@@ -21,7 +21,7 @@ namespace regional_capabilities {
 class RegionalCapabilitiesServiceClient
     : public RegionalCapabilitiesService::Client {
  public:
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   explicit RegionalCapabilitiesServiceClient(
       variations::VariationsService* variations_service);
 #else
@@ -35,7 +35,7 @@ class RegionalCapabilitiesServiceClient
   void FetchCountryId(CountryIdCallback country_id_fetched_callback) override;
 
  private:
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const int variations_country_id_;
 #endif
 };
