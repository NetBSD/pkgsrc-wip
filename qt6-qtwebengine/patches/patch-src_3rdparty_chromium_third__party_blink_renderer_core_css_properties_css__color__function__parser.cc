$NetBSD$

--- src/3rdparty/chromium/third_party/blink/renderer/core/css/properties/css_color_function_parser.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/css/properties/css_color_function_parser.cc
@@ -312,7 +312,7 @@ bool ColorFunctionParser::ConsumeChannel
 
     // Non-finite values should be clamped to the range [0, 360].
     // Since 0 = 360 in this case, they can all simply become zero.
-    if (!isfinite(channels_[i].value())) {
+    if (!std::isfinite(channels_[i].value())) {
       channels_[i] = 0.0;
     }
 
@@ -408,7 +408,7 @@ bool ColorFunctionParser::MakePerColorSp
         uses_bare_numbers = true;
       }
 
-      if (!isfinite(channels_[i].value())) {
+      if (!std::isfinite(channels_[i].value())) {
         channels_[i].value() = channels_[i].value() > 0 ? 255.0 : 0;
       } else if (!is_relative_color_) {
         // Clamp to [0, 1] range, but allow out-of-gamut relative colors.
