$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/common/mojo_core_library_support.cc.orig	2024-10-18 12:34:14.238474100 +0000
+++ content/common/mojo_core_library_support.cc
@@ -15,7 +15,7 @@ bool IsMojoCoreSharedLibraryEnabled() {
 }
 
 std::optional<base::FilePath> GetMojoCoreSharedLibraryPath() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   if (!command_line.HasSwitch(switches::kMojoCoreLibraryPath))
