$NetBSD$

--- chrome/common/extensions/command.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/common/extensions/command.cc
@@ -304,7 +304,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif defined(OS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
