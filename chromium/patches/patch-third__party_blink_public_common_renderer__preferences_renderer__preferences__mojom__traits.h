$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h.orig	2026-09-07 10:14:27.000000000 +0000
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h
@@ -130,7 +130,7 @@ struct BLINK_COMMON_EXPORT
     return data.enable_encrypted_media;
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   static const bool& use_overlay_scrollbar(
       const ::blink::RendererPreferences& data) {
     return data.use_overlay_scrollbar;
@@ -182,7 +182,7 @@ struct BLINK_COMMON_EXPORT
     return data.send_subresource_notification;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const std::string& system_font_family_name(
       const ::blink::RendererPreferences& data) {
     return data.system_font_family_name;
@@ -196,7 +196,7 @@ struct BLINK_COMMON_EXPORT
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const bool& middle_click_paste_allowed(
       const ::blink::RendererPreferences& data) {
     return data.middle_click_paste_allowed;
