$NetBSD$

Disable X264 incompatible code for X264_BUILD >= 153.

--- modules/codec/x264.c.orig	2017-11-29 23:35:29.000000000 +0000
+++ modules/codec/x264.c
@@ -842,7 +842,7 @@ static int  Open ( vlc_object_t *p_this 
     fullrange |= p_enc->fmt_in.video.b_color_range_full;
     p_enc->fmt_in.i_codec = fullrange ? VLC_CODEC_J420 : VLC_CODEC_I420;
     p_sys->i_colorspace = X264_CSP_I420;
-#if X264_BUILD >= 118
+#if X264_BUILD >= 118 && X264_BUILD < 153
     char *psz_profile = var_GetString( p_enc, SOUT_CFG_PREFIX "profile" );
     if( psz_profile )
     {
