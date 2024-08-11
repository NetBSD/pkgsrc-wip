$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/common/policy_utils.cc.orig	2024-07-24 02:44:34.804604000 +0000
+++ components/policy/core/common/policy_utils.cc
@@ -28,7 +28,7 @@ bool IsPolicyTestingEnabled(PrefService*
     return true;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (channel == version_info::Channel::DEV) {
     return true;
   }
