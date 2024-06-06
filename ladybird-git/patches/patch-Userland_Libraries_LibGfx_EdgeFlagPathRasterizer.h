$NetBSD$

popcount conflict on NetBSD.
https://github.com/SerenityOS/serenity/issues/23375

--- Userland/Libraries/LibGfx/EdgeFlagPathRasterizer.h.orig	2024-06-06 21:18:50.814506936 +0000
+++ Userland/Libraries/LibGfx/EdgeFlagPathRasterizer.h
@@ -21,7 +21,7 @@ namespace Detail {
 static auto constexpr coverage_lut = [] {
     Array<u8, 256> coverage_lut {};
     for (u32 sample = 0; sample <= 255; sample++)
-        coverage_lut[sample] = popcount(sample);
+        coverage_lut[sample] = AK::popcount(sample);
     return coverage_lut;
 }();
 
