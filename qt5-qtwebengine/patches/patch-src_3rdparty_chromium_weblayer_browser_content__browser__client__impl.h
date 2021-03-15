$NetBSD$

--- src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.h
@@ -91,7 +91,7 @@ class ContentBrowserClientImpl : public 
   scoped_refptr<content::QuotaPermissionContext> CreateQuotaPermissionContext()
       override;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
