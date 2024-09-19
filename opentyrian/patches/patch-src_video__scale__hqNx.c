$NetBSD$

Fix for unsigned comparisons.

--- src/video_scale_hqNx.c.orig	2013-09-07 23:57:23.000000000 +0000
+++ src/video_scale_hqNx.c
@@ -122,9 +122,9 @@ inline bool diff(unsigned int w1, unsign
 {
 	Uint32 YUV1 = yuv_palette[w1];
 	Uint32 YUV2 = yuv_palette[w2];
-	return ( ( abs((YUV1 & Ymask) - (YUV2 & Ymask)) > trY ) ||
-	         ( abs((YUV1 & Umask) - (YUV2 & Umask)) > trU ) ||
-	         ( abs((YUV1 & Vmask) - (YUV2 & Vmask)) > trV ) );
+	return ( ( ((YUV1 & Ymask) > (YUV2 & Ymask) + trY) && ((YUV2 & Ymask) > (YUV1 & Ymask) + trY)) ||
+	         ( ((YUV1 & Umask) > (YUV2 & Umask) + trU) && ((YUV2 & Umask) > (YUV1 & Umask) + trU)) ||
+	         ( ((YUV1 & Vmask) > (YUV2 & Vmask) + trV) && ((YUV2 & Vmask) > (YUV1 & Vmask) + trV)) );
 }
 
 
