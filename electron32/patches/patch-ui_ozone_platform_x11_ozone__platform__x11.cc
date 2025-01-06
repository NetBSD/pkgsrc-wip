$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/x11/ozone_platform_x11.cc.orig	2024-10-18 12:35:12.772251100 +0000
+++ ui/ozone/platform/x11/ozone_platform_x11.cc
@@ -193,6 +193,7 @@ class OzonePlatformX11 : public OzonePla
           base::MessagePumpType::UI;
       properties->supports_vulkan_swap_chain = true;
       properties->skia_can_fall_back_to_x11 = true;
+      properties->electron_can_call_x11 = true;
       properties->platform_shows_drag_image = false;
       properties->supports_global_application_menus = true;
       properties->app_modal_dialogs_use_event_blocker = true;
