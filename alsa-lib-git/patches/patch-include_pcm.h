$NetBSD: patch-include_pcm.h,v 1.4 2014/06/09 12:21:07 ryoon Exp $

--- include/pcm.h.orig	2016-02-24 08:33:29.000000000 +0000
+++ include/pcm.h
@@ -612,7 +612,9 @@ int snd_pcm_chmap_print(const snd_pcm_ch
 unsigned int snd_pcm_chmap_from_string(const char *str);
 snd_pcm_chmap_t *snd_pcm_chmap_parse_string(const char *str);
 
+/*
 //int snd_pcm_mixer_element(snd_pcm_t *pcm, snd_mixer_t *mixer, snd_mixer_elem_t **elem);
+ */
 
 /*
  * application helpers - these functions are implemented on top
@@ -1108,10 +1110,10 @@ int snd_pcm_format_width(snd_pcm_format_
 int snd_pcm_format_physical_width(snd_pcm_format_t format);		/* in bits */
 snd_pcm_format_t snd_pcm_build_linear_format(int width, int pwidth, int unsignd, int big_endian);
 ssize_t snd_pcm_format_size(snd_pcm_format_t format, size_t samples);
-u_int8_t snd_pcm_format_silence(snd_pcm_format_t format);
-u_int16_t snd_pcm_format_silence_16(snd_pcm_format_t format);
-u_int32_t snd_pcm_format_silence_32(snd_pcm_format_t format);
-u_int64_t snd_pcm_format_silence_64(snd_pcm_format_t format);
+uint8_t snd_pcm_format_silence(snd_pcm_format_t format);
+uint16_t snd_pcm_format_silence_16(snd_pcm_format_t format);
+uint32_t snd_pcm_format_silence_32(snd_pcm_format_t format);
+uint64_t snd_pcm_format_silence_64(snd_pcm_format_t format);
 int snd_pcm_format_set_silence(snd_pcm_format_t format, void *buf, unsigned int samples);
 
 snd_pcm_sframes_t snd_pcm_bytes_to_frames(snd_pcm_t *pcm, ssize_t bytes);
