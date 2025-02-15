$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/ui/inspectable_web_contents.cc.orig	2025-01-21 17:36:55.000000000 +0000
+++ electron/shell/browser/ui/inspectable_web_contents.cc
@@ -557,7 +557,7 @@ void InspectableWebContents::LoadComplet
           prefs.FindString("currentDockState");
       base::RemoveChars(*current_dock_state, "\"", &dock_state_);
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto* api_web_contents = api::WebContents::From(GetWebContents());
     if (api_web_contents) {
       auto* win =
