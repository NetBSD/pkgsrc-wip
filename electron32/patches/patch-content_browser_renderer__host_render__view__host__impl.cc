$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_view_host_impl.cc.orig	2024-10-18 12:34:13.578814700 +0000
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -274,7 +274,7 @@ void RenderViewHostImpl::GetPlatformSpec
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   if (command_line->HasSwitch(switches::kSystemFontFamily)) {
     prefs->system_font_family_name =
@@ -737,6 +737,11 @@ void RenderViewHostImpl::SetBackgroundOp
   GetWidget()->GetAssociatedFrameWidget()->SetBackgroundOpaque(opaque);
 }
 
+void RenderViewHostImpl::SetSchedulerThrottling(bool allowed) {
+  if (auto& broadcast = GetAssociatedPageBroadcast())
+    broadcast->SetSchedulerThrottling(allowed);
+}
+
 bool RenderViewHostImpl::IsMainFrameActive() {
   return is_active();
 }
