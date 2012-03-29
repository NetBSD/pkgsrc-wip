$NetBSD: patch-src_GPU.cpp,v 1.1 2012/03/29 21:18:27 thomasklausner Exp $

Fix build with clang.

--- src/GPU.cpp.orig	2009-11-18 20:39:36.000000000 +0000
+++ src/GPU.cpp
@@ -881,7 +881,7 @@ template<bool MOSAIC> void lineLarge8bpp
 	//TODO - handle wrapping / out of bounds correctly from rot_scale_op?
 
 	u32 tmp_map = gpu->BG_bmp_large_ram[num] + lg * YBG;
-	u8* map = MMU_gpu_map(tmp_map);
+	u8* map = (u8*)MMU_gpu_map(tmp_map);
 
 	u8* pal = MMU.ARM9_VMEM + gpu->core * ADDRESS_STEP_1KB;
 
