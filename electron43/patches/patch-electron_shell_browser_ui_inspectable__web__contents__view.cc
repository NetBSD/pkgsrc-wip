$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/browser/ui/inspectable_web_contents_view.cc.orig	2026-10-30 20:58:40.000000000 +0000
+++ electron/shell/browser/ui/inspectable_web_contents_view.cc
@@ -236,7 +236,7 @@ void InspectableWebContentsView::SetIsDo
     params.delegate = devtools_window_delegate_;
     params.bounds = inspectable_web_contents()->dev_tools_bounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_role_name = "devtools";
     if (GetDelegate())
       GetDelegate()->GetDevToolsWindowWMClass(&params.wm_class_name,
