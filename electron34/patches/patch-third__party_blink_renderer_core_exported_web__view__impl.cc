$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/exported/web_view_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/exported/web_view_impl.cc
@@ -169,6 +169,7 @@
 #include "third_party/blink/renderer/core/view_transition/view_transition_supplement.h"
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #include "third_party/blink/renderer/platform/fonts/generic_font_family_settings.h"
+#include "third_party/blink/renderer/platform/graphics/color.h"
 #include "third_party/blink/renderer/platform/graphics/image.h"
 #include "third_party/blink/renderer/platform/graphics/paint/cull_rect.h"
 #include "third_party/blink/renderer/platform/graphics/paint/paint_record_builder.h"
@@ -431,7 +432,7 @@ SkFontHinting RendererPreferencesToSkiaH
     const blink::RendererPreferences& prefs) {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   if (!prefs.should_antialias_text) {
     // When anti-aliasing is off, GTK maps all non-zero hinting settings to
     // 'Normal' hinting so we do the same. Otherwise, folks who have 'Slight'
@@ -1854,6 +1855,7 @@ void WebView::ApplyWebPreferences(const 
 #if BUILDFLAG(IS_MAC)
   web_view_impl->SetMaximumLegibleScale(
       prefs.default_maximum_page_scale_factor);
+  SetUseExternalPopupMenus(!prefs.offscreen);
 #endif
 
 #if BUILDFLAG(IS_WIN)
@@ -2456,6 +2458,10 @@ void WebViewImpl::SetPageLifecycleStateI
   TRACE_EVENT2("navigation", "WebViewImpl::SetPageLifecycleStateInternal",
                "old_state", old_state, "new_state", new_state);
 
+  // If backgroundThrottling is disabled, the page is always visible.
+  if (!scheduler_throttling_allowed_)
+      new_state->visibility = mojom::blink::PageVisibilityState::kVisible;
+
   bool storing_in_bfcache = new_state->is_in_back_forward_cache &&
                             !old_state->is_in_back_forward_cache;
   bool restoring_from_bfcache = !new_state->is_in_back_forward_cache &&
@@ -3420,7 +3426,7 @@ void WebViewImpl::UpdateFontRenderingFro
       renderer_preferences_.use_subpixel_positioning);
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) && \
     !BUILDFLAG(IS_ANDROID)
   if (!renderer_preferences_.system_font_family_name.empty()) {
     WebFontRenderStyle::SetSystemFontFamily(blink::WebString::FromUTF8(
@@ -3988,10 +3994,23 @@ PageScheduler* WebViewImpl::Scheduler() 
   return GetPage()->GetPageScheduler();
 }
 
+void WebViewImpl::SetSchedulerThrottling(bool allowed) {
+  DCHECK(GetPage());
+  scheduler_throttling_allowed_ = allowed;
+  GetPage()->GetPageScheduler()->SetPageVisible(!allowed || GetVisibilityState() == mojom::blink::PageVisibilityState::kVisible);
+}
+
 void WebViewImpl::SetVisibilityState(
     mojom::blink::PageVisibilityState visibility_state,
     bool is_initial_state) {
   DCHECK(GetPage());
+
+  if (!scheduler_throttling_allowed_) {
+    GetPage()->SetVisibilityState(mojom::blink::PageVisibilityState::kVisible, is_initial_state);
+    GetPage()->GetPageScheduler()->SetPageVisible(true);
+    return;
+  }
+
   GetPage()->SetVisibilityState(visibility_state, is_initial_state);
   // Do not throttle if the page should be painting.
   bool is_visible =
