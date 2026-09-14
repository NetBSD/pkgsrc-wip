$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/web_contents/web_contents_impl.cc.orig	2026-09-07 10:14:27.000000000 +0000
+++ content/browser/web_contents/web_contents_impl.cc
@@ -1373,7 +1373,7 @@ WebContentsImpl::WebContentsImpl(Browser
       SlowWebPreferenceCache::GetInstance());
   renderer_preferences_.caret_blink_interval =
       native_theme->caret_blink_interval();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   renderer_preferences_.use_overlay_scrollbar =
       native_theme->use_overlay_scrollbar();
 #endif
@@ -12632,7 +12632,7 @@ void WebContentsImpl::OnNativeThemeUpdat
   HandleColorRelatedStateChanges();
 
   const auto caret_blink_interval = observed_theme->caret_blink_interval();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   const auto use_overlay_scrollbar = observed_theme->use_overlay_scrollbar();
 #endif
   bool renderer_preference_changed = false;
@@ -12640,7 +12640,7 @@ void WebContentsImpl::OnNativeThemeUpdat
     renderer_preferences_.caret_blink_interval = caret_blink_interval;
     renderer_preference_changed = true;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (renderer_preferences_.use_overlay_scrollbar != use_overlay_scrollbar) {
     renderer_preferences_.use_overlay_scrollbar = use_overlay_scrollbar;
     renderer_preference_changed = true;
