$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/common/content_switches.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/common/content_switches.h
@@ -109,6 +109,7 @@ CONTENT_EXPORT extern const char kEnable
 CONTENT_EXPORT extern const char kEnableIsolatedWebAppsInRenderer[];
 CONTENT_EXPORT extern const char kEnableLCDText[];
 CONTENT_EXPORT extern const char kEnableLogging[];
+CONTENT_EXPORT extern const char kDisableUnveil[];
 CONTENT_EXPORT extern const char kEnableNetworkInformationDownlinkMax[];
 CONTENT_EXPORT extern const char kEnableCanvas2DLayers[];
 CONTENT_EXPORT extern const char kEnablePluginPlaceholderTesting[];
@@ -262,7 +263,7 @@ CONTENT_EXPORT extern const char kPreven
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 CONTENT_EXPORT extern const char kLLVMProfileFile[];
 #endif
