$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/devtools_policy_dialog.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/devtools/devtools_policy_dialog.cc
@@ -32,7 +32,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kIconPadding = 4;
 #else
 constexpr int kIconPadding = 2;
