$NetBSD$

--- components/gcm_driver/gcm_client.h.orig	2017-02-02 02:02:52.000000000 +0000
+++ components/gcm_driver/gcm_client.h
@@ -80,6 +80,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNKNOWN
   };
 
