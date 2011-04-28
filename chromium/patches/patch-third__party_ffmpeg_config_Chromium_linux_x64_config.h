$NetBSD: patch-third__party_ffmpeg_config_Chromium_linux_x64_config.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/ffmpeg/config/Chromium/linux/x64/config.h.orig	2011-04-13 08:02:48.000000000 +0000
+++ third_party/ffmpeg/config/Chromium/linux/x64/config.h
@@ -46,7 +46,7 @@
 #define HAVE_NEON 0
 #define HAVE_PPC4XX 0
 #define HAVE_SSE 1
-#define HAVE_SSSE3 1
+#define HAVE_SSSE3 0
 #define HAVE_VIS 0
 #define HAVE_BIGENDIAN 0
 #define HAVE_FAST_UNALIGNED 1
