$NetBSD$

--- chrome/test/base/testing_browser_process.h.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/test/base/testing_browser_process.h
@@ -105,8 +105,8 @@ class TestingBrowserProcess : public Bro
   DownloadStatusUpdater* download_status_updater() override;
   DownloadRequestLimiter* download_request_limiter() override;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
-  void StartAutoupdateTimer() override {}
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
+  void StartAutoupdateTimer() /*override*/ {}
 #endif
 
   net_log::ChromeNetLog* net_log() override;
