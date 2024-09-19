$NetBSD$

--- plugins/video/common/ffmpeg.h.orig	2013-02-20 02:18:05.000000000 +0000
+++ plugins/video/common/ffmpeg.h
@@ -46,6 +46,7 @@
 #include "platform.h"
 
 #include "libavcodec/avcodec.h"
+#include "libavutil/imgutils.h"
 // AVPacket was declared in avformat.h before April 2009
 #if LIBAVCODEC_VERSION_INT <= AV_VERSION_INT(52, 25, 0)
 #include "libavformat/avformat.h"
