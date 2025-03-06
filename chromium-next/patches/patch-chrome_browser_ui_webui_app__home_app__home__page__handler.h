$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/app_home/app_home_page_handler.h.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.h
@@ -24,7 +24,7 @@
 #include "mojo/public/cpp/bindings/receiver.h"
 #include "mojo/public/cpp/bindings/remote.h"
 
-static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 class ExtensionEnableFlow;
 
