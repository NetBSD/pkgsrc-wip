$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/core/embedder/features.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ mojo/core/embedder/features.h
@@ -15,7 +15,7 @@ namespace mojo {
 namespace core {
 
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(MOJO_USE_APPLE_CHANNEL)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(MOJO_CORE_EMBEDDER_FEATURES)
 BASE_DECLARE_FEATURE(kMojoLinuxChannelSharedMem);
 
