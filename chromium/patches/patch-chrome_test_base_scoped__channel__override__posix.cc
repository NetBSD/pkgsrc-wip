$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/base/scoped_channel_override_posix.cc.orig	2024-07-24 02:44:30.732209400 +0000
+++ chrome/test/base/scoped_channel_override_posix.cc
@@ -45,7 +45,7 @@ std::string GetVersionExtra(ScopedChanne
       return "beta";
     case ScopedChannelOverride::Channel::kDev:
       return "unstable";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ScopedChannelOverride::Channel::kCanary:
       return "canary";
 #endif  // BUILDFLAG(IS_LINUX)
