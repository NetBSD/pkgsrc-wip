$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/crash/crash_file_uploader.cc.orig	2025-05-30 19:50:32.000000000 +0000
+++ remoting/host/crash/crash_file_uploader.cc
@@ -44,7 +44,7 @@ constexpr char kMinidumpFileName[] = "du
 
 #if BUILDFLAG(IS_WIN)
 constexpr char kProductNameValue[] = "Chromoting";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kProductNameValue[] = "Chromoting_Linux";
 #elif BUILDFLAG(IS_MAC)
 constexpr char kProductNameValue[] = "Chromoting_Mac";
