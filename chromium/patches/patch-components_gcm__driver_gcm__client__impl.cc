$NetBSD$

--- components/gcm_driver/gcm_client_impl.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ components/gcm_driver/gcm_client_impl.cc
@@ -135,6 +135,9 @@ void ToCheckinProtoVersion(
     case GCMClient::PLATFORM_CROS:
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_CROS;
       break;
+    case GCMClient::PLATFORM_BSD:
+      platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
+      break;
     case GCMClient::PLATFORM_UNSPECIFIED:
       // For unknown platform, return as LINUX.
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
