$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feed/core/v2/proto_util.cc.orig	2024-07-24 02:44:34.048530800 +0000
+++ components/feed/core/v2/proto_util.cc
@@ -93,8 +93,8 @@ feedwire::Version GetPlatformVersionMess
 
   int32_t major, minor, revision;
   base::SysInfo::OperatingSystemVersionNumbers(&major, &minor, &revision);
-  result.set_major(major);
-  result.set_minor(minor);
+  result.set_gmajor(major);
+  result.set_gminor(minor);
   result.set_revision(revision);
 #if BUILDFLAG(IS_ANDROID)
   result.set_api_version(base::android::BuildInfo::GetInstance()->sdk_int());
@@ -109,8 +109,8 @@ feedwire::Version GetAppVersionMessage(c
   // Chrome's version is in the format: MAJOR,MINOR,BUILD,PATCH.
   const std::vector<uint32_t>& numbers = chrome_info.version.components();
   if (numbers.size() > 3) {
-    result.set_major(static_cast<int32_t>(numbers[0]));
-    result.set_minor(static_cast<int32_t>(numbers[1]));
+    result.set_gmajor(static_cast<int32_t>(numbers[0]));
+    result.set_gminor(static_cast<int32_t>(numbers[1]));
     result.set_build(static_cast<int32_t>(numbers[2]));
     result.set_revision(static_cast<int32_t>(numbers[3]));
   }
