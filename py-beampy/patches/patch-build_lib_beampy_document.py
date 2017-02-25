$NetBSD$

--- build/lib/beampy/document.py.orig	2017-01-26 20:59:10.000000000 +0000
+++ build/lib/beampy/document.py
@@ -186,24 +186,7 @@ class document():
         missing = False
         for progname, cmd in self.options['external_app'].items():
             if cmd == 'auto':
-
-                #Special case of video_encoder (ffmpeg or avconv)
-                if progname == 'video_encoder':
-                    find_ffmpeg = find_executable('ffmpeg')
-                    find_avconv = find_executable('avconv')
-                    if find_ffmpeg != None:
-                        document._external_cmd[progname] = find_ffmpeg
-                    elif find_avconv != None:
-                        document._external_cmd[progname] = find_avconv
-                    else:
-                        missing = True
-                else:
-                    find_app = find_executable( progname )
-                    if find_app != None:
-                        document._external_cmd[progname] = find_app
-                    else:
-                        missing = True
-
+                document._external_cmd[progname] = '@PREFIX@/bin/ffmpeg3'
             else:
                 document._external_cmd[progname] = cmd
 
