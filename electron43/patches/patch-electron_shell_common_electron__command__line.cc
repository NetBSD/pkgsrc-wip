$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/common/electron_command_line.cc.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/shell/common/electron_command_line.cc
@@ -39,7 +39,7 @@ std::vector<std::string> ElectronCommand
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ElectronCommandLine::InitializeFromCommandLine() {
   argv() = base::CommandLine::ForCurrentProcess()->argv();
