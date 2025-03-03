$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/electron_command_line.h.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/common/electron_command_line.h
@@ -22,7 +22,7 @@ class ElectronCommandLine {
 
   static void Init(int argc, base::CommandLine::CharType** argv);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux the command line has to be read from base::CommandLine since
   // it is using zygote.
   static void InitializeFromCommandLine();
