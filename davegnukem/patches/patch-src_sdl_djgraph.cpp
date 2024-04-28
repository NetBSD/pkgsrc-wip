$NetBSD$

Fix compile error when compiling on big-endian systems.

--- src/sdl/djgraph.cpp.orig	2024-04-27 19:31:52.959084051 -0400
+++ src/sdl/djgraph.cpp	2024-04-27 19:33:17.530349103 -0400
@@ -182,7 +182,7 @@
 		//fixme this won't work bigendian
 		#if SDL_BYTEORDER==SDL_BIG_ENDIAN
 		// Not yet supported for big-endian platforms (dj2019-06)
-		if (false)
+		if (false) {}
 		#else
 		if (g_nSimulatedGraphics>0) //'Simulate' CGA/EGA
 		{
