$NetBSD$

--- components/gcm_driver/gcm_client_impl.cc.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/gcm_driver/gcm_client_impl.cc
@@ -137,6 +137,9 @@ void ToCheckinProtoVersion(
     case GCMClient::PLATFORM_CROS:
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_CROS;
       break;
+    case GCMClient::PLATFORM_BSD: // TODO what the hell are those?
+      platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
+      break;
     case GCMClient::PLATFORM_UNKNOWN:
       // For unknown platform, return as LINUX.
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
