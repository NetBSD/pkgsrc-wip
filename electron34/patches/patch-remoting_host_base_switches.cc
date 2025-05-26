$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- remoting/host/base/switches.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ remoting/host/base/switches.cc
@@ -23,13 +23,13 @@ const char kProcessTypeEvaluateCapabilit
 const char kProcessTypeFileChooser[] = "file_chooser";
 const char kProcessTypeUrlForwarderConfigurator[] =
     "url_forwarder_configurator";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kProcessTypeXSessionChooser[] = "xsession_chooser";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 const char kEvaluateCapabilitySwitchName[] = "evaluate-type";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kEnableUtempter[] = "enable-utempter";
 #endif
 
