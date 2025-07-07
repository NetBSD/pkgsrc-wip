$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/test/test_browser_ui.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/test/test_browser_ui.cc
@@ -19,7 +19,7 @@
 #include "ui/views/widget/widget.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #include "ui/base/test/skia_gold_matching_algorithm.h"
 #include "ui/compositor/compositor.h"
@@ -33,7 +33,7 @@
 #endif
 
 // TODO(crbug.com/40625383) support Mac for pixel tests.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define SUPPORTS_PIXEL_TEST
 #endif
 
