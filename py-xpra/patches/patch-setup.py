$NetBSD$

--- setup.py.orig	2016-06-04 03:39:58.000000000 +0000
+++ setup.py
@@ -992,7 +992,6 @@ if 'clean' in sys.argv or 'sdist' in sys
                    "xpra/codecs/v4l2/pusher.c",
                    "xpra/codecs/xvid/encoder.c",
                    "xpra/codecs/libav_common/av_log.c",
-                   "xpra/codecs/v4l/pusher.c",
                    "xpra/codecs/webp/encode.c",
                    "xpra/codecs/webp/decode.c",
                    "xpra/codecs/dec_avcodec2/decoder.c",
