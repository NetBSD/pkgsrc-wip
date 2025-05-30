$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/common/content_switches.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/common/content_switches.cc
@@ -347,6 +347,8 @@ const char kEnableIsolatedWebAppsInRende
 // builds.
 const char kEnableLogging[]                 = "enable-logging";
 
+const char kDisableUnveil[]                 = "disable-unveil";
+
 // Enables the type, downlinkMax attributes of the NetInfo API. Also, enables
 // triggering of change attribute of the NetInfo API when there is a change in
 // the connection type.
@@ -954,7 +956,7 @@ const char kPreventResizingContentsForTe
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
