$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/web_frame_test.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/frame/web_frame_test.cc
@@ -291,6 +291,7 @@ void ExecuteScriptsInMainWorld(
       DOMWrapperWorld::kMainWorldId, sources, user_gesture,
       mojom::blink::EvaluationTiming::kSynchronous,
       mojom::blink::LoadEventBlockingOption::kDoNotBlock, std::move(callback),
+      base::NullCallback(),
       BackForwardCacheAware::kAllow,
       mojom::blink::WantResultOption::kWantResult, wait_for_promise);
 }
@@ -6474,7 +6475,7 @@ TEST_F(WebFrameTest, DISABLED_PositionFo
 }
 
 #if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1090246): Fix these tests on Fuchsia and re-enable.
 // TODO(crbug.com/1317375): Build these tests on all platforms.
 #define MAYBE_SelectRangeStaysHorizontallyAlignedWhenMoved \
@@ -6883,7 +6884,7 @@ TEST_F(CompositedSelectionBoundsTest, La
 TEST_F(CompositedSelectionBoundsTest, LargeSelectionNoScroll) {
   RunTest("composited_selection_bounds_large_selection_noscroll.html");
 }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_ANDROID)
 TEST_F(CompositedSelectionBoundsTest, Input) {
   web_view_helper_.GetWebView()->GetSettings()->SetDefaultFontSize(16);
