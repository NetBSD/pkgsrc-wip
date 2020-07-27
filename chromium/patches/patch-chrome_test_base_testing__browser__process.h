$NetBSD$

--- chrome/test/base/testing_browser_process.h.orig	2020-07-08 21:40:37.000000000 +0000
+++ chrome/test/base/testing_browser_process.h
@@ -119,8 +119,10 @@ class TestingBrowserProcess : public Bro
   DownloadRequestLimiter* download_request_limiter() override;
   StartupData* startup_data() override;
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
+#if (defined(OS_WIN) || (defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   void StartAutoupdateTimer() override {}
+#elif defined(OS_BSD)
+  void StartAutoupdateTimer() {}
 #endif
 
   component_updater::ComponentUpdateService* component_updater() override;
