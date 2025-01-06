$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gtk/window_frame_provider_gtk.cc.orig	2024-10-18 12:35:12.728268900 +0000
+++ ui/gtk/window_frame_provider_gtk.cc
@@ -29,20 +29,23 @@ constexpr int kMaxFrameSizeDip = 64;
 // will get an incorrect hint as to which pixels are fully opaque.
 constexpr int kMaxCornerRadiusDip = 32;
 
-GtkCssContext WindowContext(bool solid_frame, bool tiled, bool focused) {
+GtkCssContext WindowContext(bool solid_frame, bool tiled, bool maximized, bool focused) {
   std::string selector = "window.background.";
   selector += solid_frame ? "solid-csd" : "csd";
   if (tiled) {
     selector += ".tiled";
   }
+  if (maximized) {
+    selector += ".maximized";
+  }
   if (!focused) {
     selector += ":inactive";
   }
   return AppendCssNodeToStyleContext({}, selector);
 }
 
-GtkCssContext DecorationContext(bool solid_frame, bool tiled, bool focused) {
-  auto context = WindowContext(solid_frame, tiled, focused);
+GtkCssContext DecorationContext(bool solid_frame, bool tiled, bool maximized, bool focused) {
+  auto context = WindowContext(solid_frame, tiled, maximized, focused);
   // GTK4 renders the decoration directly on the window.
   if (!GtkCheckVersion(4)) {
     context = AppendCssNodeToStyleContext(context, "decoration");
@@ -61,8 +64,8 @@ GtkCssContext DecorationContext(bool sol
   return context;
 }
 
-GtkCssContext HeaderContext(bool solid_frame, bool tiled, bool focused) {
-  auto context = WindowContext(solid_frame, tiled, focused);
+GtkCssContext HeaderContext(bool solid_frame, bool tiled, bool maximized, bool focused) {
+  auto context = WindowContext(solid_frame, tiled, maximized, focused);
   context =
       AppendCssNodeToStyleContext(context, "headerbar.header-bar.titlebar");
   if (!focused) {
@@ -117,8 +120,8 @@ int ComputeTopCornerRadius() {
   // need to experimentally determine the corner radius by rendering a sample.
   // Additionally, in GTK4, the headerbar corners get clipped by the window
   // rather than the headerbar having its own rounded corners.
-  auto context = GtkCheckVersion(4) ? DecorationContext(false, false, false)
-                                    : HeaderContext(false, false, false);
+  auto context = GtkCheckVersion(4) ? DecorationContext(false, false, false, false)
+                                    : HeaderContext(false, false, false, false);
   ApplyCssToContext(context, R"(window, headerbar {
     background-image: none;
     background-color: black;
@@ -152,7 +155,7 @@ int ComputeTopCornerRadius() {
 bool HeaderIsTranslucent() {
   // The arbitrary square size to render a sample header.
   constexpr int kHeaderSize = 32;
-  auto context = HeaderContext(false, false, false);
+  auto context = HeaderContext(false, false, false, false);
   double opacity = GetOpacityFromContext(context);
   if (opacity < 1.0) {
     return true;
@@ -186,8 +189,8 @@ WindowFrameProviderGtk::Asset& WindowFra
 
 WindowFrameProviderGtk::Asset::~Asset() = default;
 
-WindowFrameProviderGtk::WindowFrameProviderGtk(bool solid_frame, bool tiled)
-    : solid_frame_(solid_frame), tiled_(tiled) {
+WindowFrameProviderGtk::WindowFrameProviderGtk(bool solid_frame, bool tiled, bool maximized)
+    : solid_frame_(solid_frame), tiled_(tiled), maximized_(maximized) {
   GtkSettings* settings = gtk_settings_get_default();
   // Unretained() is safe since WindowFrameProviderGtk will own the signals.
   auto callback = base::BindRepeating(&WindowFrameProviderGtk::OnThemeChanged,
@@ -337,7 +340,7 @@ void WindowFrameProviderGtk::PaintWindow
 
   auto header =
       PaintHeaderbar({client_bounds_px.width(), top_area_height_px},
-                     HeaderContext(solid_frame_, tiled_, focused), scale);
+                     HeaderContext(solid_frame_, tiled_, maximized_, focused), scale);
   image = gfx::ImageSkia::CreateFrom1xBitmap(header);
   // In GTK4, the headerbar gets clipped by the window.
   if (GtkCheckVersion(4)) {
@@ -366,7 +369,7 @@ WindowFrameProviderGtk::Asset& WindowFra
 
   gfx::Rect frame_bounds_dip(kMaxFrameSizeDip, kMaxFrameSizeDip,
                              2 * kMaxFrameSizeDip, 2 * kMaxFrameSizeDip);
-  auto focused_context = DecorationContext(solid_frame_, tiled_, true);
+  auto focused_context = DecorationContext(solid_frame_, tiled_, maximized_, true);
   frame_bounds_dip.Inset(-GtkStyleContextGetPadding(focused_context));
   frame_bounds_dip.Inset(-GtkStyleContextGetBorder(focused_context));
   gfx::Size bitmap_size(BitmapSizePx(asset), BitmapSizePx(asset));
@@ -374,7 +377,7 @@ WindowFrameProviderGtk::Asset& WindowFra
                                      focused_context, scale);
   asset.unfocused_bitmap =
       PaintBitmap(bitmap_size, gfx::RectF(frame_bounds_dip),
-                  DecorationContext(solid_frame_, tiled_, false), scale);
+                  DecorationContext(solid_frame_, tiled_, maximized_, false), scale);
 
   return asset;
 }
