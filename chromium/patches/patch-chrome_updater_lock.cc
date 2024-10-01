$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/updater/lock.cc.orig	2024-09-24 20:49:23.161394800 +0000
+++ chrome/updater/lock.cc
@@ -26,7 +26,7 @@ namespace updater {
 std::unique_ptr<ScopedLock> CreateScopedLock(const std::string& name,
                                              UpdaterScope scope,
                                              base::TimeDelta timeout) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return named_system_lock::ScopedLock::Create(
       base::StrCat({"/" PRODUCT_FULLNAME_STRING, name,
                     UpdaterScopeToString(scope), ".lock"}),
