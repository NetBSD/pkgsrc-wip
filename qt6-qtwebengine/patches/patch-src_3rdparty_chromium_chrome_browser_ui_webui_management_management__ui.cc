$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/management/management_ui.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/management/management_ui.cc
@@ -98,11 +98,11 @@ content::WebUIDataSource* CreateAndAddMa
       {kManagementOnFileTransferVisibleData,
        IDS_MANAGEMENT_FILE_TRANSFER_VISIBLE_DATA},
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {kManagementScreenCaptureEvent, IDS_MANAGEMENT_SCREEN_CAPTURE_EVENT},
       {kManagementScreenCaptureData, IDS_MANAGEMENT_SCREEN_CAPTURE_DATA},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {kManagementDeviceSignalsDisclosure,
        IDS_MANAGEMENT_DEVICE_SIGNALS_DISCLOSURE},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
