$NetBSD$

--- chrome/browser/native_file_system/chrome_native_file_system_permission_context.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/native_file_system/chrome_native_file_system_permission_context.cc
@@ -120,12 +120,13 @@ const struct {
     {base::DIR_APP_DATA, nullptr, true},
     {base::DIR_HOME, FILE_PATH_LITERAL("Library"), true},
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On Linux also block access to devices via /dev, as well as security
     // sensitive data in /sys and /proc.
     {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), true},
     {kNoBasePathKey, FILE_PATH_LITERAL("/sys"), true},
     {kNoBasePathKey, FILE_PATH_LITERAL("/proc"), true},
+    {kNoBasePathKey, FILE_PATH_LITERAL("/kern"), true},
     // And block all of ~/.config, matching the similar restrictions on mac
     // and windows.
     {base::DIR_HOME, FILE_PATH_LITERAL(".config"), true},
