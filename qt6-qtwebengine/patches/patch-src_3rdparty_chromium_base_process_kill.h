$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/process/kill.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/process/kill.h
@@ -123,7 +123,7 @@ BASE_EXPORT TerminationStatus GetTermina
 BASE_EXPORT TerminationStatus GetKnownDeadTerminationStatus(
     ProcessHandle handle, int* exit_code);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
