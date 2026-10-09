$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/api/electron_api_screen.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/api/electron_api_screen.cc
@@ -29,7 +29,7 @@
 #include "ui/display/win/screen_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/x11_util.h"
 #endif
 
@@ -91,7 +91,7 @@ Screen::~Screen() {
 }
 
 gfx::Point Screen::GetCursorScreenPoint(v8::Isolate* isolate) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsWayland())
     return {};
 #endif
@@ -165,7 +165,7 @@ void Screen::OnDisplayMetricsChanged(con
 gfx::PointF Screen::ScreenToDIPPoint(const gfx::PointF& point_px) {
 #if BUILDFLAG(IS_WIN)
   return display::win::GetScreenWin()->ScreenToDIPPoint(point_px);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsX11()) {
     gfx::Point pt_px = gfx::ToFlooredPoint(point_px);
     display::Display display = GetDisplayNearestPoint(pt_px);
@@ -184,7 +184,7 @@ gfx::PointF Screen::ScreenToDIPPoint(con
 gfx::Point Screen::DIPToScreenPoint(const gfx::Point& point_dip) {
 #if BUILDFLAG(IS_WIN)
   return display::win::GetScreenWin()->DIPToScreenPoint(point_dip);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (x11_util::IsX11()) {
     display::Display display = GetDisplayNearestPoint(point_dip);
     gfx::Rect bounds_dip = display.bounds();
@@ -226,7 +226,7 @@ gin::ObjectTemplateBuilder Screen::GetOb
       .SetMethod("getPrimaryDisplay", &Screen::GetPrimaryDisplay)
       .SetMethod("getAllDisplays", &Screen::GetAllDisplays)
       .SetMethod("getDisplayNearestPoint", &Screen::GetDisplayNearestPoint)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       .SetMethod("screenToDipPoint", &Screen::ScreenToDIPPoint)
       .SetMethod("dipToScreenPoint", &Screen::DIPToScreenPoint)
 #endif
