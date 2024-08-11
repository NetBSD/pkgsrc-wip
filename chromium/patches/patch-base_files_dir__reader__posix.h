$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/dir_reader_posix.h.orig	2024-07-24 02:44:22.559418000 +0000
+++ base/files/dir_reader_posix.h
@@ -17,7 +17,7 @@
 // seems worse than falling back to enumerating all file descriptors so we will
 // probably never implement this on the Mac.
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "base/files/dir_reader_linux.h"
 #else
 #include "base/files/dir_reader_fallback.h"
@@ -25,7 +25,7 @@
 
 namespace base {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 typedef DirReaderLinux DirReaderPosix;
 #else
 typedef DirReaderFallback DirReaderPosix;
