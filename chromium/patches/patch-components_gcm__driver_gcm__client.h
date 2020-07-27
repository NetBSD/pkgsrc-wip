$NetBSD$

--- components/gcm_driver/gcm_client.h.orig	2020-07-08 21:40:39.000000000 +0000
+++ components/gcm_driver/gcm_client.h
@@ -87,6 +87,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNSPECIFIED
   };
 
