$NetBSD$

--- gfx/thebes/gfxFont.cpp.orig	2017-09-15 04:15:37.000000000 +0000
+++ gfx/thebes/gfxFont.cpp
@@ -841,8 +841,16 @@ gfxFont::GetRoundOffsetsToPixels(DrawTar
   }
 
   // Sometimes hint metrics gets set for us, most notably for printing.
+#ifdef MOZ_TREE_CAIRO
   cairo_hint_metrics_t hint_metrics =
     cairo_scaled_font_get_hint_metrics(scaled_font);
+#else
+  cairo_font_options_t* font_options = cairo_font_options_create();
+  cairo_scaled_font_get_font_options(scaled_font, font_options);
+  cairo_hint_metrics_t hint_metrics =
+    cairo_font_options_get_hint_metrics(font_options);
+  cairo_font_options_destroy(font_options);
+#endif
 
   switch (hint_metrics) {
   case CAIRO_HINT_METRICS_OFF:
