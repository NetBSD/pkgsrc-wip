$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/app/content_main.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ content/app/content_main.cc
@@ -233,7 +233,7 @@ NO_STACK_PROTECTOR int RunContentProcess
     base::EnableTerminationOnOutOfMemory();
     logging::RegisterAbslAbortHook();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
@@ -332,7 +332,7 @@ NO_STACK_PROTECTOR int RunContentProcess
 #endif
 #endif
 
-#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) && !defined(COMPONENT_BUILD)
+#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) && !defined(COMPONENT_BUILD) && defined(notyet)
     base::subtle::EnableFDOwnershipEnforcement(true);
 #endif
 
