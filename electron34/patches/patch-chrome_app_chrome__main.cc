$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/app/chrome_main.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/app/chrome_main.cc
@@ -28,11 +28,11 @@
 #include "chrome/app/chrome_main_mac.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/base_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/app/chrome_main_linux.h"
 #endif
 
@@ -57,7 +57,7 @@
 // sometime after old headless code is removed from Chrome.
 // See https://crbug.com/373672160.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #define ENABLE_OLD_HEADLESS_INFO
 #endif
 
@@ -115,7 +115,7 @@ int ChromeMain(int argc, const char** ar
 #error Unknown platform.
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PossiblyDetermineFallbackChromeChannel(argv[0]);
 #endif
 
@@ -181,7 +181,7 @@ int ChromeMain(int argc, const char** ar
   SetUpBundleOverrides();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   AppendExtraArgumentsToCommandLine(command_line);
 #endif
 
