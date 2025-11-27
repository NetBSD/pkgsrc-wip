$NetBSD$

specify std namespace

--- src/3rdparty/chromium/third_party/blink/renderer/core/css/properties/css_color_function_parser.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/css/properties/css_color_function_parser.cc
@@ -399,7 +399,7 @@ void ColorFunctionParser::MakePerColorSp
     if (channels[i].has_value() && ColorChannelIsHue(color_space, i)) {
       // Non-finite values should be clamped to the range [0, 360].
       // Since 0 = 360 in this case, they can all simply become zero.
-      if (!isfinite(channels[i].value())) {
+      if (!std::isfinite(channels[i].value())) {
         channels[i] = 0.0;
       }
 
@@ -414,7 +414,7 @@ void ColorFunctionParser::MakePerColorSp
       if (!channels[i].has_value()) {
         continue;
       }
-      if (!isfinite(channels[i].value())) {
+      if (!std::isfinite(channels[i].value())) {
         channels[i].value() = channels[i].value() > 0 ? 255.0 : 0;
       } else if (!is_relative_color) {
         // Clamp to [0, 1] range, but allow out-of-gamut relative colors.
