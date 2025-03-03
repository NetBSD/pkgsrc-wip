$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/osr/osr_host_display_client.cc.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/browser/osr/osr_host_display_client.cc
@@ -96,7 +96,7 @@ void OffScreenHostDisplayClient::CreateL
   layered_window_updater_->SetActive(active_);
 }
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 void OffScreenHostDisplayClient::DidCompleteSwapWithNewSize(
     const gfx::Size& size) {}
 #endif
