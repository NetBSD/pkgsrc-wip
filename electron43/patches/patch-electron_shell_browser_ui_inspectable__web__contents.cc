$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/ui/inspectable_web_contents.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/ui/inspectable_web_contents.cc
@@ -619,7 +619,7 @@ void InspectableWebContents::LoadComplet
           dock_state_ = "right";
         }
       }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       auto* api_web_contents = api::WebContents::From(GetWebContents());
       if (api_web_contents) {
         auto* win =
