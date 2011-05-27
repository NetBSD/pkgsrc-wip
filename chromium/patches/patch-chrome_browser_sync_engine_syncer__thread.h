$NetBSD: patch-chrome_browser_sync_engine_syncer__thread.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/browser/sync/engine/syncer_thread.h.orig	2011-05-24 08:01:38.000000000 +0000
+++ chrome/browser/sync/engine/syncer_thread.h
@@ -26,7 +26,7 @@
 #include "chrome/browser/sync/syncable/model_type.h"
 #include "chrome/common/deprecated/event_sys-inl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/sync/engine/idle_query_linux.h"
 #endif
 
@@ -339,7 +339,7 @@ class SyncerThread : public base::RefCou
       NudgeSource source,
       const sessions::TypePayloadMap& model_types_with_payloads);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, we need this information in order to query idle time.
   scoped_ptr<IdleQueryLinux> idle_query_;
 #endif
