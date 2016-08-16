$NetBSD$

--- src/VBox/Devices/Audio/DrvHostOSSAudio.cpp.orig	2016-08-15 22:22:04.000000000 +0000
+++ src/VBox/Devices/Audio/DrvHostOSSAudio.cpp
@@ -137,6 +137,7 @@ static OSSAUDIOCFG s_OSSConf =
 };
 
 
+#ifndef __NetBSD__
 /* http://www.df.lth.se/~john_e/gems/gem002d.html */
 static uint32_t popcount(uint32_t u)
 {
@@ -147,7 +148,7 @@ static uint32_t popcount(uint32_t u)
     u = ( u&0x0000ffff) + (u>>16);
     return u;
 }
-
+#endif
 
 static uint32_t lsbindex(uint32_t u)
 {
@@ -1174,4 +1175,3 @@ const PDMDRVREG g_DrvHostOSSAudio =
     /* u32EndVersion */
     PDM_DRVREG_VERSION
 };
-
