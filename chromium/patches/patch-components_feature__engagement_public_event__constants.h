$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feature_engagement/public/event_constants.h.orig	2024-07-24 02:44:34.032529000 +0000
+++ components/feature_engagement/public/event_constants.h
@@ -14,7 +14,7 @@ namespace events {
 
 // Desktop
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
