$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/app/content_main.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/content/app/content_main.cc
@@ -66,7 +66,7 @@
 #include "content/common/shared_file_util.h"
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/scoped_file.h"
 #endif
 
@@ -229,7 +229,7 @@ NO_STACK_PROTECTOR int RunContentProcess
 #endif
     logging::RegisterAbslAbortHook();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
@@ -316,7 +316,7 @@ NO_STACK_PROTECTOR int RunContentProcess
     command_line->AppendSwitch(switches::kUseMobileUserAgent);
 #endif
 
-#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) && !defined(COMPONENT_BUILD)
+#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(COMPONENT_BUILD) && defined(notyet)
     base::subtle::EnableFDOwnershipEnforcement(true);
 #endif
 
