$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/embedder_support/user_agent_utils.cc.orig	2024-07-24 02:44:33.940520300 +0000
+++ components/embedder_support/user_agent_utils.cc
@@ -445,6 +445,9 @@ std::string GetPlatformForUAMetadata() {
 # else
   return "Chromium OS";
 # endif
+#elif BUILDFLAG(IS_BSD)
+  // The internet is weird...
+  return "Linux";
 #else
   return std::string(version_info::GetOSType());
 #endif
