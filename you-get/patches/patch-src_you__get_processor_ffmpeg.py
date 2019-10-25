$NetBSD$

Also look and use ffmpeg[234] if possible.

--- src/you_get/processor/ffmpeg.py.orig	2019-09-09 21:15:04.000000000 +0000
+++ src/you_get/processor/ffmpeg.py
@@ -31,7 +31,12 @@ def get_usable_ffmpeg(cmd):
     except:
         return None
 
-FFMPEG, FFPROBE, FFMPEG_VERSION = get_usable_ffmpeg('ffmpeg') or get_usable_ffmpeg('avconv') or (None, None, None)
+FFMPEG, FFPROBE, FFMPEG_VERSION = get_usable_ffmpeg('ffmpeg') or \
+    get_usable_ffmpeg('ffmpeg4') or \
+    get_usable_ffmpeg('ffmpeg3') or \
+    get_usable_ffmpeg('ffmpeg2') or \
+    get_usable_ffmpeg('avconv') or \
+    (None, None, None)
 if logging.getLogger().isEnabledFor(logging.DEBUG):
     LOGLEVEL = ['-loglevel', 'info']
     STDIN = None
