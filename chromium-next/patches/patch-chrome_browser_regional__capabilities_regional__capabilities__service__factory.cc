$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc.orig	2025-03-20 19:11:33.000000000 +0000
+++ chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc
@@ -12,7 +12,7 @@
 #include "chrome/browser/regional_capabilities/regional_capabilities_service_client.h"
 #include "components/regional_capabilities/regional_capabilities_service.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/variations/service/variations_service.h"
 #endif
 
@@ -57,7 +57,7 @@ RegionalCapabilitiesServiceFactory::Buil
   Profile* profile = Profile::FromBrowserContext(context);
   auto regional_capabilities_service_client =
       std::make_unique<RegionalCapabilitiesServiceClient>(
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           g_browser_process->variations_service()
 #endif
       );
