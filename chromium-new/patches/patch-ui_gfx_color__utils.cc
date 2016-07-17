$NetBSD$

--- ui/gfx/color_utils.cc.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/gfx/color_utils.cc
@@ -42,7 +42,7 @@ int calcHue(double temp1, double temp2, 
   else if (hue * 3.0 < 2.0)
     result = temp1 + (temp2 - temp1) * (2.0 / 3.0 - hue) * 6.0;
 
-  return static_cast<int>(std::round(result * 255));
+  return static_cast<int>(round(result * 255));
 }
 
 // Assumes sRGB.
@@ -85,7 +85,7 @@ double GetRelativeLuminance(SkColor colo
 }
 
 uint8_t GetLuma(SkColor color) {
-  return static_cast<uint8_t>(std::round((0.299 * SkColorGetR(color)) +
+  return static_cast<uint8_t>(round((0.299 * SkColorGetR(color)) +
                                          (0.587 * SkColorGetG(color)) +
                                          (0.114 * SkColorGetB(color))));
 }
@@ -223,9 +223,9 @@ SkColor HSLShift(SkColor color, const HS
     b += (255.0 - b) * ((shift.l - 0.5) * 2.0);
   }
   return SkColorSetARGB(alpha,
-                        static_cast<int>(std::round(r)),
-                        static_cast<int>(std::round(g)),
-                        static_cast<int>(std::round(b)));
+                        static_cast<int>(round(r)),
+                        static_cast<int>(round(g)),
+                        static_cast<int>(round(b)));
 }
 
 void BuildLumaHistogram(const SkBitmap& bitmap, int histogram[256]) {
@@ -275,10 +275,10 @@ SkColor AlphaBlend(SkColor foreground, S
   double b = (SkColorGetB(foreground) * f_weight +
               SkColorGetB(background) * b_weight) / 255.0;
 
-  return SkColorSetARGB(static_cast<int>(std::round(normalizer)),
-                        static_cast<int>(std::round(r)),
-                        static_cast<int>(std::round(g)),
-                        static_cast<int>(std::round(b)));
+  return SkColorSetARGB(static_cast<int>(round(normalizer)),
+                        static_cast<int>(round(r)),
+                        static_cast<int>(round(g)),
+                        static_cast<int>(round(b)));
 }
 
 bool IsDark(SkColor color) {
