$NetBSD$

--- src/tools/pw-loopback.c.orig	2024-10-21 17:07:29.288463859 +0000
+++ src/tools/pw-loopback.c
@@ -115,7 +115,11 @@ int main(int argc, char *argv[])
 	struct spa_error_location loc;
 
 	setlocale(LC_ALL, "");
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	data.channels = DEFAULT_CHANNELS;
 	data.opt_channel_map = DEFAULT_CHANNEL_MAP;
@@ -273,7 +277,11 @@ exit:
 		pw_main_loop_destroy(data.loop);
 	pw_properties_free(data.capture_props);
 	pw_properties_free(data.playback_props);
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 
 	return res;
 }
