$NetBSD: patch-chrome_browser_sync_engine_syncer__thread.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/sync/engine/syncer_thread.cc.orig	2011-04-13 08:01:39.000000000 +0000
+++ chrome/browser/sync/engine/syncer_thread.cc
@@ -263,7 +263,7 @@ void SyncerThread::ThreadMainLoop() {
   bool initial_sync_for_thread = true;
   bool continue_sync_cycle = false;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   idle_query_.reset(new IdleQueryLinux());
 #endif
 
@@ -358,7 +358,7 @@ void SyncerThread::ThreadMainLoop() {
         static_cast<int>(vault_.current_wait_interval_.poll_delta.InSeconds()),
         &user_idle_milliseconds, &continue_sync_cycle, nudged);
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   idle_query_.reset();
 #endif
 }
@@ -832,7 +832,7 @@ int SyncerThread::UserIdleTime() {
     return 0;
   }
   return idle_time / 1000000;  // nano to milli
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (idle_query_.get())
     return idle_query_->IdleTime();
   return 0;
