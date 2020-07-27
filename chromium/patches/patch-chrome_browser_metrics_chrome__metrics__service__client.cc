$NetBSD$

--- chrome/browser/metrics/chrome_metrics_service_client.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/metrics/chrome_metrics_service_client.cc
@@ -685,7 +685,7 @@ void ChromeMetricsServiceClient::Registe
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<DesktopPlatformFeaturesMetricsProvider>());
 #endif  //  defined(OS_WIN) || defined(OS_MACOSX) || \
@@ -951,7 +951,7 @@ bool ChromeMetricsServiceClient::Registe
   }
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   // This creates the DesktopProfileSessionDurationsServices if it didn't exist
   // already.
   metrics::DesktopProfileSessionDurationsServiceFactory::GetForBrowserContext(
