$NetBSD$

--- src/tools/pw-cat.c.orig	2024-10-21 16:46:32.481500875 +0000
+++ src/tools/pw-cat.c
@@ -1612,7 +1612,11 @@ int main(int argc, char *argv[])
 	struct spa_error_location loc;
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 #ifdef HAVE_PW_CAT_FFMPEG_INTEGRATION
 	av_log_set_level(AV_LOG_DEBUG);
@@ -2078,7 +2082,11 @@ error_no_main_loop:
 	if (data.encoded.format_context)
 		avformat_close_input(&data.encoded.format_context);
 #endif
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 	return exit_code;
 
 error_usage:
