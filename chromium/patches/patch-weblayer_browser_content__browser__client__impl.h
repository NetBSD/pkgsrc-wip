$NetBSD$

--- weblayer/browser/content_browser_client_impl.h.orig	2020-07-15 18:56:49.000000000 +0000
+++ weblayer/browser/content_browser_client_impl.h
@@ -111,7 +111,7 @@ class ContentBrowserClientImpl : public 
   void RenderProcessWillLaunch(content::RenderProcessHost* host) override;
   scoped_refptr<content::QuotaPermissionContext> CreateQuotaPermissionContext()
       override;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
