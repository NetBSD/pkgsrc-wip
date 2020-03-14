$NetBSD$

Add support for NetBSD audio.

--- libavdevice/nbsdaudio.c.orig	2020-03-14 15:39:35.169889227 +0000
+++ libavdevice/nbsdaudio.c
@@ -0,0 +1,129 @@
+/*
+ * NetBSD play and grab interface
+ * Copyright (c) 2020 Yorick Hardy
+ *
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
+#include "config.h"
+
+#include <string.h>
+
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+#include <fcntl.h>
+#include <sys/audioio.h>
+#include <sys/ioctl.h>
+
+#include "libavutil/log.h"
+
+#include "libavcodec/avcodec.h"
+#include "avdevice.h"
+
+#include "nbsdaudio.h"
+
+int ff_nbsdaudio_audio_open(AVFormatContext *s1, int is_output,
+                          const char *audio_device)
+{
+    NBSDAudioData *s = s1->priv_data;
+    audio_info_t info;
+    struct audio_prinfo *prinfo;
+    int audio_fd, err;
+
+    if (is_output)
+        audio_fd = avpriv_open(audio_device, O_WRONLY);
+    else
+        audio_fd = avpriv_open(audio_device, O_RDONLY);
+    if (audio_fd < 0) {
+        av_log(s1, AV_LOG_ERROR, "%s: %s\n", audio_device, av_err2str(AVERROR(errno)));
+        return AVERROR(EIO);
+    }
+
+#if 0
+    /* non blocking mode */
+    if (!is_output) {
+        if (fcntl(audio_fd, F_SETFL, O_NONBLOCK) < 0) {
+            av_log(s1, AV_LOG_WARNING, "%s: Could not enable non block mode (%s)\n", audio_device, av_err2str(AVERROR(errno)));
+        }
+    }
+#endif
+
+    s->frame_size = NBSDAUDIO_BLOCK_SIZE;
+
+#define CHECK_IOCTL_ERROR(event)                                              \
+    if (err < 0) {                                                            \
+        av_log(s1, AV_LOG_ERROR, #event ": %s\n", av_err2str(AVERROR(errno)));\
+        goto fail;                                                            \
+    }
+
+    AUDIO_INITINFO(&info);
+
+    if (is_output) {
+        prinfo = &(info.play);
+        info.mode = AUMODE_PLAY;
+    } else {
+        prinfo = &(info.record);
+        info.mode = AUMODE_RECORD;
+    }
+
+    prinfo->encoding = AUDIO_ENCODING_SLINEAR;
+    prinfo->sample_rate = s->sample_rate;
+    prinfo->channels = s->channels;
+    prinfo->precision = 16;
+    prinfo->pause = 0;
+    
+    err=ioctl(audio_fd, AUDIO_SETINFO, &info);
+    CHECK_IOCTL_ERROR(AUDIO_SETINFO)
+
+    err=ioctl(audio_fd, AUDIO_GETINFO, &info);
+    CHECK_IOCTL_ERROR(AUDIO_GETINFO)
+
+    s->fd = audio_fd;
+    if (is_output) {
+        s->sample_rate = prinfo->sample_rate;
+        s->channels = prinfo->channels;
+    } else {
+        s->sample_rate = prinfo->sample_rate;
+        s->channels = prinfo->channels;
+    }
+
+    switch(prinfo->encoding) {
+    case AUDIO_ENCODING_SLINEAR_LE:
+        s->codec_id = AV_CODEC_ID_PCM_S16LE;
+        break;
+    case AUDIO_ENCODING_SLINEAR_BE:
+        s->codec_id = AV_CODEC_ID_PCM_S16BE;
+        break;
+    default:
+        av_log(s1, AV_LOG_ERROR, "Soundcard does not support signed 16 bit sample format\n");
+        close(audio_fd);
+        return AVERROR(EIO);
+    }
+
+    return 0;
+ fail:
+    close(audio_fd);
+    return AVERROR(EIO);
+#undef CHECK_IOCTL_ERROR
+}
+
+int ff_nbsdaudio_audio_close(NBSDAudioData *s)
+{
+    close(s->fd);
+    return 0;
+}
