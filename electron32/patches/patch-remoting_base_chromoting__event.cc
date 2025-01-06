$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- remoting/base/chromoting_event.cc.orig	2024-10-18 12:34:31.745882700 +0000
+++ remoting/base/chromoting_event.cc
@@ -192,7 +192,7 @@ void ChromotingEvent::AddSystemInfo() {
   SetString(kCpuKey, base::SysInfo::OperatingSystemArchitecture());
   SetString(kOsVersionKey, base::SysInfo::OperatingSystemVersion());
   SetString(kWebAppVersionKey, STRINGIZE(VERSION));
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   Os os = Os::CHROMOTING_LINUX;
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   Os os = Os::CHROMOTING_CHROMEOS;
