$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2024-10-18 12:34:13.606800300 +0000
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -120,7 +120,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/browser/accessibility/browser_accessibility_auralinux.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/text_input_flags.h"
@@ -479,7 +479,7 @@ gfx::NativeViewAccessible RenderWidgetHo
     return ToBrowserAccessibilityWin(manager->GetBrowserAccessibilityRoot())
         ->GetCOM();
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserAccessibilityManager* manager =
       host()->GetOrCreateRootBrowserAccessibilityManager();
   if (manager && manager->GetBrowserAccessibilityRoot())
@@ -580,8 +580,8 @@ void RenderWidgetHostViewAura::ShowImpl(
   // OnShowWithPageVisibility will not call NotifyHostAndDelegateOnWasShown,
   // which updates `visibility_`, unless the host is hidden. Make sure no update
   // is needed.
-  CHECK(host_->is_hidden() || visibility_ == Visibility::VISIBLE);
-  OnShowWithPageVisibility(page_visibility);
+  if (host_->is_hidden() || visibility_ == Visibility::VISIBLE)
+    OnShowWithPageVisibility(page_visibility);
 }
 
 void RenderWidgetHostViewAura::EnsurePlatformVisibility(
@@ -644,7 +644,7 @@ void RenderWidgetHostViewAura::HideImpl(
   CHECK(visibility_ == Visibility::HIDDEN ||
         visibility_ == Visibility::OCCLUDED);
 
-  if (!host()->is_hidden()) {
+  if (!host()->is_hidden() && !host()->disable_hidden_) {
     host()->WasHidden();
     aura::WindowTreeHost* host = window_->GetHost();
       aura::Window* parent = window_->parent();
@@ -1736,7 +1736,7 @@ bool RenderWidgetHostViewAura::ShouldDoL
   return host() && host()->delegate() && host()->delegate()->ShouldDoLearning();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderWidgetHostViewAura::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
@@ -2564,7 +2564,7 @@ bool RenderWidgetHostViewAura::NeedsInpu
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return NeedsInputGrab();
 #else
   return false;
@@ -2748,7 +2748,7 @@ void RenderWidgetHostViewAura::ForwardKe
   if (!target_host)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::LinuxUi::instance();
   std::vector<ui::TextEditCommandAuraLinux> commands;
   if (!event.skip_if_unhandled && linux_ui && event.os_event &&
@@ -2946,6 +2946,12 @@ void RenderWidgetHostViewAura::OnTextSel
   }
 }
 
+void RenderWidgetHostViewAura::OnFocusedInputElementChanged(
+    TextInputManager* text_input_manager,
+    RenderWidgetHostViewBase* view) {
+  FocusedNodeChanged(false, {});
+}
+
 void RenderWidgetHostViewAura::SetPopupChild(
     RenderWidgetHostViewAura* popup_child_host_view) {
   popup_child_host_view_ = popup_child_host_view;
