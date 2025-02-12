$NetBSD$

--- src/3rdparty/chromium/third_party/blink/renderer/core/style/style_crossfade_image.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/style/style_crossfade_image.cc
@@ -318,7 +318,7 @@ std::vector<float> StyleCrossfadeImage::
   if (num_missing > 0) {
     float equal_share = std::max(1.0f - sum, 0.0f) / num_missing;
     for (float& weight : result) {
-      if (isnan(weight)) {
+      if (std::isnan(weight)) {
         weight = equal_share;
       }
     }
