$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/test/base/scoped_channel_override_posix.cc.orig	2024-10-18 12:34:04.127847000 +0000
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
