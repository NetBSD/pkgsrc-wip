$NetBSD$

--- pipewire-jack/src/pipewire-jack.c.orig	2024-09-27 10:02:20.000000000 +0000
+++ pipewire-jack/src/pipewire-jack.c
@@ -7552,7 +7552,11 @@ int jack_get_video_image_size(jack_clien
 static void reg(void) __attribute__ ((constructor));
 static void reg(void)
 {
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(NULL, NULL);
+#else
+	pipewire_init(NULL, NULL);
+#endif
 	PW_LOG_TOPIC_INIT(jack_log_topic);
 	pthread_mutex_init(&globals.lock, NULL);
 	pw_array_init(&globals.descriptions, 16);
@@ -7572,5 +7576,9 @@ static void unreg(void)
 		free(o);
 	}
 	pthread_mutex_unlock(&globals.lock);
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 }
