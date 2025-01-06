$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/web_frame_test.cc.orig	2024-10-18 12:34:35.424175000 +0000
+++ third_party/blink/renderer/core/frame/web_frame_test.cc
@@ -294,6 +294,7 @@ void ExecuteScriptsInMainWorld(
       DOMWrapperWorld::kMainWorldId, sources, user_gesture,
       mojom::blink::EvaluationTiming::kSynchronous,
       mojom::blink::LoadEventBlockingOption::kDoNotBlock, std::move(callback),
+      base::NullCallback(),
       BackForwardCacheAware::kAllow,
       mojom::blink::WantResultOption::kWantResult, wait_for_promise);
 }
@@ -6477,7 +6478,7 @@ TEST_F(WebFrameTest, DISABLED_PositionFo
 }
 
 #if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1090246): Fix these tests on Fuchsia and re-enable.
 // TODO(crbug.com/1317375): Build these tests on all platforms.
 #define MAYBE_SelectRangeStaysHorizontallyAlignedWhenMoved \
@@ -6886,7 +6887,7 @@ TEST_F(CompositedSelectionBoundsTest, La
 TEST_F(CompositedSelectionBoundsTest, LargeSelectionNoScroll) {
   RunTest("composited_selection_bounds_large_selection_noscroll.html");
 }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_ANDROID)
 TEST_F(CompositedSelectionBoundsTest, Input) {
   web_view_helper_.GetWebView()->GetSettings()->SetDefaultFontSize(16);
