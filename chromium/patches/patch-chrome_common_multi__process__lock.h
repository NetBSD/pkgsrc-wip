$NetBSD: patch-chrome_common_multi__process__lock.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/multi_process_lock.h.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/multi_process_lock.h
@@ -18,7 +18,7 @@ class MultiProcessLock {
   // The length of a multi-process lock name is limited on Linux, so
   // it is limited it on all platforms for consistency. This length does
   // not include a terminator.
-  static const size_t MULTI_PROCESS_LOCK_NAME_MAX_LEN = 106;
+  static const size_t MULTI_PROCESS_LOCK_NAME_MAX_LEN = 102;
 
   // Factory method for creating a multi-process lock.
   // |name| is the name of the lock. The name has special meaning on Windows
