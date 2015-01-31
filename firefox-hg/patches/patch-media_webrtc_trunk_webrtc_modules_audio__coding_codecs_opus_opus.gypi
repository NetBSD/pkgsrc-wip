$NetBSD: patch-media_webrtc_trunk_webrtc_modules_audio__coding_codecs_opus_opus.gypi,v 1.2 2015/01/31 09:12:06 thomasklausner Exp $

--- media/webrtc/trunk/webrtc/modules/audio_coding/codecs/opus/opus.gypi.orig	2015-01-31 08:17:36.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/audio_coding/codecs/opus/opus.gypi
@@ -16,19 +16,9 @@
       'type': 'static_library',
       'conditions': [
         ['build_with_mozilla==1', {
-          # Mozilla provides its own build of the opus library.
-          'include_dirs': [
-            '/media/libopus/include',
-            '/media/libopus/src',
-            '/media/libopus/celt',
+          'cflags_mozilla': [
+            '$(MOZ_OPUS_CFLAGS)',
           ],
-          'direct_dependent_settings': {
-            'include_dirs': [
-              '/media/libopus/include',
-              '/media/libopus/src',
-              '/media/libopus/celt',
-            ],
-          },
         }, {
           'dependencies': [
             '<(DEPTH)/third_party/opus/opus.gyp:opus'
