$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/files/important_file_writer_cleaner.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/files/important_file_writer_cleaner.cc
@@ -25,7 +25,8 @@ namespace base {
 namespace {
 
 base::Time GetUpperBoundTime() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA)
+// needed because of .CreationTime() pledge
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // If process creation time is not available then use instance creation
   // time as the upper-bound for old files. Modification times may be
   // rounded-down to coarse-grained increments, e.g. FAT has 2s granularity,
