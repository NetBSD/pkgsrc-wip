$NetBSD$

Disable the SSE4 code so that older CPU's are supported.

--- OpenTESArena/src/Rendering/SoftwareRenderer.cpp.orig	2020-03-27 01:34:48.000000000 +0000
+++ OpenTESArena/src/Rendering/SoftwareRenderer.cpp
@@ -4397,6 +4397,7 @@ void SoftwareRenderer::drawDistantPixels
 	double vStart, double vEnd, const SkyTexture &texture, bool emissive,
 	const ShadingInfo &shadingInfo, const FrameView &frame)
 {
+#if 0
 	// @todo: fix. this is now out of sync with the non-SSE version.
 
 	// Draw range values.
@@ -4537,6 +4538,7 @@ void SoftwareRenderer::drawDistantPixels
 			}
 		}
 	}
+#endif
 }
 
 /*void SoftwareRenderer::drawDistantPixelsAVX(int x, const DrawRange &drawRange, double u,
