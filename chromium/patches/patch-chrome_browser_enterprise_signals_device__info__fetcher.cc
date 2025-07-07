$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/signals/device_info_fetcher.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/enterprise/signals/device_info_fetcher.cc
@@ -10,7 +10,7 @@
 #include "chrome/browser/enterprise/signals/device_info_fetcher_mac.h"
 #elif BUILDFLAG(IS_WIN)
 #include "chrome/browser/enterprise/signals/device_info_fetcher_win.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/device_info_fetcher_linux.h"
 #endif
 
@@ -76,7 +76,7 @@ std::unique_ptr<DeviceInfoFetcher> Devic
   return CreateInstanceInternal();
 }
 
-#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_WIN) && \
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD) && \
     !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 // static
 std::unique_ptr<DeviceInfoFetcher> DeviceInfoFetcher::CreateInstanceInternal() {
