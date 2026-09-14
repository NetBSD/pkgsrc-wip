$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/openscreen/src/cast/common/channel/message_util.cc.orig	2026-09-07 10:14:27.000000000 +0000
+++ third_party/openscreen/src/cast/common/channel/message_util.cc
@@ -59,7 +59,7 @@ constexpr VirtualConnectPlatformValue Ge
   return kMacOSX;
 #elif BUILDFLAG(IS_CHROMEOS)
   return kChromeOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kLinux;
 #else
   return kOtherPlatform;
