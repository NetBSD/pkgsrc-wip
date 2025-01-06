$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/electron_command_line.cc.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/shell/common/electron_command_line.cc
@@ -26,7 +26,7 @@ void ElectronCommandLine::Init(int argc,
   argv_.assign(argv, argv + argc);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ElectronCommandLine::InitializeFromCommandLine() {
   argv_ = base::CommandLine::ForCurrentProcess()->argv();
