$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.cc
@@ -48,7 +48,7 @@
 #include "ui/base/ui_base_switches.h"
 #include "ui/gfx/switches.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crash_switches.h"  // nogncheck
 #include "components/crash/core/app/crashpad.h"        // nogncheck
 #include "content/public/common/content_descriptors.h"
@@ -66,7 +66,7 @@
 
 namespace headless {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace {
 
 int GetCrashSignalFD(const base::CommandLine& command_line,
@@ -164,7 +164,7 @@ HeadlessContentBrowserClient::GetGenerat
   return content::GeneratedCodeCacheSettings(true, 0, context->GetPath());
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void HeadlessContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -183,7 +183,7 @@ void HeadlessContentBrowserClient::Appen
 
   command_line->AppendSwitch(::switches::kHeadless);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   int fd;
   pid_t pid;
   if (crash_reporter::GetHandlerSocket(&fd, &pid)) {
