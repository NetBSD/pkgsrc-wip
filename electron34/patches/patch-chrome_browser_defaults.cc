$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/defaults.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/defaults.cc
@@ -44,7 +44,7 @@ const bool kShowHelpMenuItemIcon = true;
 const bool kShowHelpMenuItemIcon = false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
