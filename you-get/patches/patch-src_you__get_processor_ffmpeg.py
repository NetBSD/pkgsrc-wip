$NetBSD$

Also look and use ffmpeg[23] if possible.

--- src/you_get/processor/ffmpeg.py.orig	2017-07-23 21:09:38.000000000 +0000
+++ src/you_get/processor/ffmpeg.py
@@ -32,7 +32,11 @@ def get_usable_ffmpeg(cmd):
     except:
         return None
 
-FFMPEG, FFMPEG_VERSION = get_usable_ffmpeg('ffmpeg') or get_usable_ffmpeg('avconv') or (None, None)
+FFMPEG, FFMPEG_VERSION = get_usable_ffmpeg('ffmpeg') or \
+    get_usable_ffmpeg('ffmpeg3') or \
+    get_usable_ffmpeg('ffmpeg2') or \
+    get_usable_ffmpeg('avconv') or \
+    (None, None)
 if logging.getLogger().isEnabledFor(logging.DEBUG):
     LOGLEVEL = ['-loglevel', 'info']
     STDIN = None
