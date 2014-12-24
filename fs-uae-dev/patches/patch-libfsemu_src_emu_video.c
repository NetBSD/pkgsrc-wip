$NetBSD: patch-libfsemu_src_emu_video.c,v 1.1 2014/12/24 20:17:47 rhialto Exp $

NetBSD has no `long double roundl(long double)'. Fortunately these calls
don't need such precision.

--- libfsemu/src/emu/video.c.orig	2014-09-27 12:00:45.000000000 +0000
+++ libfsemu/src/emu/video.c
@@ -112,7 +112,7 @@ void fs_emu_set_video_frame_rate(double 
     last_frame_rate = frame_rate;
     last_frame_rate_host = g_fs_emu_video_frame_rate_host;
 
-    int frame_rate_i = roundl(frame_rate);
+    int frame_rate_i = round(frame_rate);
     fs_log("fs_emu_set_video_frame_rate: %0.2f (%d)\n",
            frame_rate, frame_rate_i);
     g_video_frame_rate = frame_rate;
