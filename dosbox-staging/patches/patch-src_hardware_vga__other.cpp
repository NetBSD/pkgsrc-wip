$NetBSD$

--- src/hardware/vga_other.cpp.orig	2023-01-07 07:06:28.000000000 +0000
+++ src/hardware/vga_other.cpp
@@ -569,7 +569,7 @@ static void update_cga16_color_pcjr()
 
 			auto to_linear_rgb = [=](const float v) -> uint8_t {
 				// Only operate on reasonably positive v-values
-				if (!isnormal(v) || v <= 0.0f)
+				if (!std::isnormal(v) || v <= 0.0f)
 					return 0;
 				// switch to linear RGB space and scale to the 8-bit range
 				constexpr int max_8bit = UINT8_MAX;
