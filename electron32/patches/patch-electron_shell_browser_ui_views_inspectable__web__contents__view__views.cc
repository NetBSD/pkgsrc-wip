$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/ui/views/inspectable_web_contents_view_views.cc.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/browser/ui/views/inspectable_web_contents_view_views.cc
@@ -184,7 +184,7 @@ void InspectableWebContentsViewViews::Se
     params.delegate = devtools_window_delegate_;
     params.bounds = inspectable_web_contents()->dev_tools_bounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_role_name = "devtools";
     if (GetDelegate())
       GetDelegate()->GetDevToolsWindowWMClass(&params.wm_class_name,
