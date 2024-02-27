$NetBSD$

Fix compilation on NetBSD.
https://github.com/SerenityOS/serenity/issues/23375

--- Userland/Libraries/LibGfx/EdgeFlagPathRasterizer.h.orig	2024-02-27 18:16:47.107269492 +0000
+++ Userland/Libraries/LibGfx/EdgeFlagPathRasterizer.h
@@ -18,7 +18,7 @@ namespace Gfx {
 
 namespace Detail {
 
-static auto constexpr coverage_lut = [] {
+static auto coverage_lut = [] {
     Array<u8, 256> coverage_lut {};
     for (u32 sample = 0; sample <= 255; sample++)
         coverage_lut[sample] = popcount(sample);
