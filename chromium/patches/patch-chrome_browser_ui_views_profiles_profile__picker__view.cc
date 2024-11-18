$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_picker_view.cc.orig	2024-11-14 01:04:04.829566200 +0000
+++ chrome/browser/ui/views/profiles/profile_picker_view.cc
@@ -88,7 +88,7 @@
 #include "chrome/browser/ui/views/profiles/first_run_flow_controller_lacros.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -118,7 +118,7 @@ class ProfilePickerWidget : public views
     views::Widget::InitParams params(
         views::Widget::InitParams::NATIVE_WIDGET_OWNS_WIDGET);
     params.delegate = profile_picker_view_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_class_name = shell_integration_linux::GetProgramClassName();
     params.wm_class_class = shell_integration_linux::GetProgramClassClass();
     params.wayland_app_id = params.wm_class_class;
