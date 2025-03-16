$NetBSD: patch-remoting_base_host__settings.cc,v 1.1 2025/02/06 09:58:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/base/host_settings.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/base/host_settings.cc
@@ -7,7 +7,7 @@
 #include "base/no_destructor.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_APPLE) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(IS_APPLE) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 #include "remoting/base/file_host_settings.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -44,7 +44,7 @@ HostSettings::~HostSettings() = default;
 
 // static
 HostSettings* HostSettings::GetInstance() {
-#if BUILDFLAG(IS_APPLE) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(IS_APPLE) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
   static base::NoDestructor<FileHostSettings> instance(
       FileHostSettings::GetSettingsFilePath());
 #elif BUILDFLAG(IS_WIN)
