$NetBSD$

specify std namespace

--- src/3rdparty/chromium/third_party/blink/renderer/core/css/properties/css_color_function_parser.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/css/properties/css_color_function_parser.cc
@@ -394,7 +394,7 @@ void ColorFunctionParser::MakePerColorSp
       if (channel_types_[i] == ChannelType::kNone) {
         continue;
       }
-      if (!isfinite(channels_[i].value())) {
+      if (!std::isfinite(channels_[i].value())) {
         channels_[i].value() = channels_[i].value() > 0 ? 255.0 : 0;
       } else if (!IsRelativeColor()) {
         // Clamp to [0, 1] range, but allow out-of-gamut relative colors.
@@ -651,7 +651,7 @@ CSSValue* ColorFunctionParser::ConsumeFu
         if (ColorChannelIsHue(color_space_, i)) {
           // Non-finite values should be clamped to the range [0, 360].
           // Since 0 = 360 in this case, they can all simply become zero.
-          if (!isfinite(channels_[i].value())) {
+          if (!std::isfinite(channels_[i].value())) {
             channels_[i] = 0.0;
           }
 
