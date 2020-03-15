$NetBSD$

Add support for NetBSD audio.

--- libavdevice/nbsdaudio.h.orig	2020-03-15 19:23:38.138784844 +0000
+++ libavdevice/nbsdaudio.h
@@ -0,0 +1,43 @@
+/*
+ * This file is part of FFmpeg.
+ *
+ * FFmpeg is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2.1 of the License, or (at your option) any later version.
+ *
+ * FFmpeg is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General Public
+ * License along with FFmpeg; if not, write to the Free Software
+ * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
+ */
+
+#ifndef AVDEVICE_NBSDAUDIO_H
+#define AVDEVICE_NBSDAUDIO_H
+
+#include "libavcodec/avcodec.h"
+
+#include "libavformat/avformat.h"
+
+typedef struct NBSDAudioData {
+    AVClass *class;
+    int fd;
+    int sample_rate;
+    int channels;
+    int frame_size; /* in bytes ! */
+    int precision;
+    enum AVCodecID codec_id;
+    uint8_t *buffer;
+    int buffer_ptr;
+} NBSDAudioData;
+
+int ff_nbsdaudio_audio_open(AVFormatContext *s1, int is_output,
+                            const char *audio_device);
+
+int ff_nbsdaudio_audio_close(NBSDAudioData *s);
+
+#endif /* AVDEVICE_NBSDAUDIO_H */
