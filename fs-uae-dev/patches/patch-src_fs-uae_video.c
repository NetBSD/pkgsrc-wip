$NetBSD: patch-src_fs-uae_video.c,v 1.1 2014/12/24 20:17:47 rhialto Exp $

NetBSD has no `long double roundl(long double)'. Fortunately these calls
don't need such precision.

--- src/fs-uae/video.c.orig	2014-10-20 10:07:57.000000000 +0000
+++ src/fs-uae/video.c
@@ -581,13 +581,13 @@ static void display_screen()
     }
 #endif
     fs_emu_video_buffer_set_current(g_buffer);
-    if (roundl(g_last_refresh_rate) == -1) {
-        if (roundl(fs_emu_get_video_frame_rate()) != TURBO_FRAME_RATE) {
+    if (round(g_last_refresh_rate) == -1) {
+        if (round(fs_emu_get_video_frame_rate()) != TURBO_FRAME_RATE) {
             fs_emu_notification(45194412, _("Warp mode enabled"));
         }
         fs_emu_set_video_frame_rate(TURBO_FRAME_RATE);
     } else {
-        if (roundl(fs_emu_get_video_frame_rate()) == TURBO_FRAME_RATE) {
+        if (round(fs_emu_get_video_frame_rate()) == TURBO_FRAME_RATE) {
             fs_emu_notification(45194412, _("Warp mode disabled"));
         }
         fs_emu_set_video_frame_rate(g_last_refresh_rate);
