$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/named_system_lock/lock.h.orig	2024-10-18 12:34:06.898340700 +0000
+++ components/named_system_lock/lock.h
@@ -38,7 +38,7 @@ class ScopedLock {
   // may acquire that lock. The lock name has different meanings per platform:
   // Linux: A shared memory object name starting with `/`. E.g. `/MyApp.lock`.
   // Mac: A bootstrap service name (see `man bootstrap_check_in`).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<ScopedLock> Create(const std::string& name,
                                             base::TimeDelta timeout);
 #elif BUILDFLAG(IS_WIN)
