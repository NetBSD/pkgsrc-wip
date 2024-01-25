$NetBSD$

Add Sun audio support

--- src/audio_priv.h.orig	2021-07-30 08:54:26.000000000 +0000
+++ src/audio_priv.h
@@ -115,6 +115,11 @@ create_oss_object(const char *device,
                   const char *application_name,
                   const char *description);
 
+struct audio_object *
+create_sun_object(const char *device,
+                  const char *application_name,
+                  const char *description);
+
 #endif
 #endif
 
