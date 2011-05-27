$NetBSD: patch-chrome_common_service__process__util__posix.h,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- chrome/common/service_process_util_posix.h.orig	2011-05-24 08:01:58.000000000 +0000
+++ chrome/common/service_process_util_posix.h
@@ -14,7 +14,7 @@
 #include "base/message_pump_libevent.h"
 #include "base/scoped_ptr.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/common/multi_process_lock.h"
 MultiProcessLock* TakeServiceRunningLock(bool waiting);
 #endif  // OS_LINUX
@@ -65,7 +65,7 @@ struct ServiceProcessState::StateData
   FilePathWatcher executable_watcher_;
   ServiceProcessState* state_;
 #endif  // OS_MACOSX
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   scoped_ptr<MultiProcessLock> initializing_lock_;
   scoped_ptr<MultiProcessLock> running_lock_;
 #endif  // OS_LINUX
