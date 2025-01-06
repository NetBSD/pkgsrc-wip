$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/device_signals/core/system_signals/platform_delegate.cc.orig	2024-10-18 12:34:06.658470200 +0000
+++ components/device_signals/core/system_signals/platform_delegate.cc
@@ -11,7 +11,7 @@ namespace device_signals {
 
 bool CustomFilePathComparator::operator()(const base::FilePath& a,
                                           const base::FilePath& b) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, the file system is case sensitive.
   return a < b;
 #else
