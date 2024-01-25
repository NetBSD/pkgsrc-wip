$NetBSD$

Add Sun audio support

--- src/audio.c.orig	2017-01-08 13:01:50.000000000 +0000
+++ src/audio.c
@@ -94,7 +94,10 @@ create_audio_device_object(const char *d
 #if defined(__APPLE__)
 	if ((object = create_coreaudio_object(device, application_name, description)) != NULL)
 		return object;
-
+#else
+#if defined(_SUNAUDIO)       
+	if ((object = create_sun_object(device, application_name, description)) != NULL)
+		return object;
 #else
 	if ((object = create_pulseaudio_object(device, application_name, description)) != NULL)
 		return object;
@@ -106,5 +109,6 @@ create_audio_device_object(const char *d
 		return object;
 #endif
 #endif
+#endif
 	return NULL;
 }
