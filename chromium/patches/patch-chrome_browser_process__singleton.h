$NetBSD: patch-chrome_browser_process__singleton.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/process_singleton.h.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/process_singleton.h
@@ -67,7 +67,7 @@ class ProcessSingleton : public base::No
   // instance.
   NotifyResult NotifyOtherProcessOrCreate();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Exposed for testing.  We use a timeout on Linux, and in tests we want
   // this timeout to be short.
   NotifyResult NotifyOtherProcessWithTimeout(const CommandLine& command_line,
