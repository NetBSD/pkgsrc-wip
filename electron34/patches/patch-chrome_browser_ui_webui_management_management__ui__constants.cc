$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/webui/management/management_ui_constants.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/webui/management/management_ui_constants.cc
@@ -89,12 +89,12 @@ const char kProfileReportingExtension[] 
 const char kProfileReportingPolicy[] = "profileReportingPolicy";
 const char kProfileReportingLearnMore[] = "profileReportingLearnMore";
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kManagementScreenCaptureEvent[] = "managementScreenCaptureEvent";
 const char kManagementScreenCaptureData[] = "managementScreenCaptureData";
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kManagementDeviceSignalsDisclosure[] =
     "managementDeviceSignalsDisclosure";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
