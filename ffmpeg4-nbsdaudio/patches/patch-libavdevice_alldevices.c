$NetBSD$

Add support for NetBSD audio.

--- libavdevice/alldevices.c.orig	2019-12-31 21:35:24.000000000 +0000
+++ libavdevice/alldevices.c
@@ -40,6 +40,8 @@ extern AVInputFormat  ff_iec61883_demuxe
 extern AVInputFormat  ff_jack_demuxer;
 extern AVInputFormat  ff_kmsgrab_demuxer;
 extern AVInputFormat  ff_lavfi_demuxer;
+extern AVInputFormat  ff_nbsdaudio_demuxer;
+extern AVOutputFormat ff_nbsdaudio_muxer;
 extern AVInputFormat  ff_openal_demuxer;
 extern AVOutputFormat ff_opengl_muxer;
 extern AVInputFormat  ff_oss_demuxer;
