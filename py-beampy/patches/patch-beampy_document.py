$NetBSD$

--- beampy/document.py.orig	2017-01-26 20:59:10.000000000 +0000
+++ beampy/document.py
@@ -189,7 +189,7 @@ class document():
 
                 #Special case of video_encoder (ffmpeg or avconv)
                 if progname == 'video_encoder':
-                    find_ffmpeg = find_executable('ffmpeg')
+                    find_ffmpeg = find_executable('ffmpeg3')
                     find_avconv = find_executable('avconv')
                     if find_ffmpeg != None:
                         document._external_cmd[progname] = find_ffmpeg
