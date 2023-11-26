$NetBSD$

i_music needs cmath for log10f and powf (exposed by turning
pre-compiled headers off).

--- source/common/audio/music/i_music.h.orig	2023-11-12 13:35:34.000000000 +0000
+++ source/common/audio/music/i_music.h
@@ -34,6 +34,8 @@
 #ifndef __I_MUSIC_H__
 #define __I_MUSIC_H__
 
+#include <cmath>
+
 //
 //	MUSIC I/O
 //
