$NetBSD$

--- chrome/browser/browser_process_impl.cc.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/browser_process_impl.cc
@@ -162,7 +162,7 @@
 #include "chrome/browser/media/webrtc_log_uploader.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/memory/tab_manager.h"
 #endif
 
@@ -778,7 +778,7 @@ gcm::GCMDriver* BrowserProcessImpl::gcm_
 
 memory::TabManager* BrowserProcessImpl::GetTabManager() {
   DCHECK(CalledOnValidThread());
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (!tab_manager_.get())
     tab_manager_.reset(new memory::TabManager());
   return tab_manager_.get();
