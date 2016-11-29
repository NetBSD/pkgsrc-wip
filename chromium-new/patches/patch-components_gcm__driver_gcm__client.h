$NetBSD$

--- components/gcm_driver/gcm_client.h.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/gcm_driver/gcm_client.h
@@ -80,6 +80,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNKNOWN
   };
 
