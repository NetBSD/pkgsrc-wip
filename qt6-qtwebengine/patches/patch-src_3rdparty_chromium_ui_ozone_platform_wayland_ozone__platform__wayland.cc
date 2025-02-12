$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/ozone/platform/wayland/ozone_platform_wayland.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/ui/ozone/platform/wayland/ozone_platform_wayland.cc
@@ -66,13 +66,13 @@
 #include "ui/events/ozone/layout/stub/stub_keyboard_layout_engine.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/platform/wayland/host/wayland_cursor_factory.h"
 #else
 #include "ui/ozone/common/bitmap_cursor_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/platform/wayland/host/linux_ui_delegate_wayland.h"
 #endif
 
@@ -267,7 +267,7 @@ class OzonePlatformWayland : public Ozon
 
     buffer_manager_connector_ = std::make_unique<WaylandBufferManagerConnector>(
         connection_->buffer_manager_host());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     cursor_factory_ = std::make_unique<WaylandCursorFactory>(connection_.get());
 #else
     cursor_factory_ = std::make_unique<BitmapCursorFactory>();
@@ -277,7 +277,7 @@ class OzonePlatformWayland : public Ozon
 
     supported_buffer_formats_ =
         connection_->buffer_manager_host()->GetSupportedBufferFormats();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     linux_ui_delegate_ =
         std::make_unique<LinuxUiDelegateWayland>(connection_.get());
 #endif
@@ -514,7 +514,7 @@ class OzonePlatformWayland : public Ozon
   DrmRenderNodePathFinder path_finder_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<LinuxUiDelegateWayland> linux_ui_delegate_;
 #endif
 };
