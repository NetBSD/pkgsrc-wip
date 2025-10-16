$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/icons/icon_masker.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/web_applications/icons/icon_masker.cc
@@ -12,7 +12,7 @@
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void MaskIconOnOs(SkBitmap input_bitmap, MaskedIconCallback masked_callback) {
   base::SequencedTaskRunner::GetCurrentDefault()->PostTask(
       FROM_HERE,
