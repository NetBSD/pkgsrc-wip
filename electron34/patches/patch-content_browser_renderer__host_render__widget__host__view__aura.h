$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_view_aura.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/render_widget_host_view_aura.h
@@ -275,7 +275,7 @@ class CONTENT_EXPORT RenderWidgetHostVie
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
@@ -650,6 +650,8 @@ class CONTENT_EXPORT RenderWidgetHostVie
       RenderWidgetHostViewBase* updated_view) override;
   void OnTextSelectionChanged(TextInputManager* text_input_mangager,
                               RenderWidgetHostViewBase* updated_view) override;
+  void OnFocusedInputElementChanged(TextInputManager* text_input_manager,
+                                    RenderWidgetHostViewBase* view) override;
 
   // Detaches |this| from the input method object.
   // is_removed flag is true if this is called while the window is
