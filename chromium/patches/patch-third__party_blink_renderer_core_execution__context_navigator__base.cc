$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/execution_context/navigator_base.cc.orig	2024-09-24 20:49:36.452561100 +0000
+++ third_party/blink/renderer/core/execution_context/navigator_base.cc
@@ -31,7 +31,7 @@ String GetReducedNavigatorPlatform() {
   return "Win32";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return "Linux x86_64";
 #elif BUILDFLAG(IS_IOS)
   return "iPhone";
