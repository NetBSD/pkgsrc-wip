$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/browser.h.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/shell/browser/browser.h
@@ -144,7 +144,7 @@ class Browser : private WindowListObserv
 
   std::u16string GetApplicationNameForProtocol(const GURL& url);
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // get the name, icon and path for an application
   v8::Local<v8::Promise> GetApplicationInfoForProtocol(v8::Isolate* isolate,
                                                        const GURL& url);
@@ -272,10 +272,10 @@ class Browser : private WindowListObserv
   PCWSTR GetAppUserModelID();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Whether Unity launcher is running.
   bool IsUnityRunning();
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   // Tell the application to open a file.
   bool OpenFile(const std::string& file_path);
