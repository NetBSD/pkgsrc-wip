$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/printing/print_backend_service_manager.cc.orig	2024-10-18 12:34:01.873093000 +0000
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -36,7 +36,7 @@
 #include "printing/printing_context.h"
 #include "printing/printing_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #endif
 
@@ -877,7 +877,7 @@ PrintBackendServiceManager::GetServiceFr
         host.BindNewPipeAndPassReceiver(),
         content::ServiceProcessHost::Options()
             .WithDisplayName(IDS_UTILITY_PROCESS_PRINT_BACKEND_SERVICE_NAME)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
             .WithExtraCommandLineSwitches({switches::kMessageLoopTypeUi})
 #endif
             .Pass());
@@ -1054,7 +1054,7 @@ PrintBackendServiceManager::DetermineIdl
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (HasQueryWithUiClientForRemoteId(remote_id)) {
         return std::nullopt;
