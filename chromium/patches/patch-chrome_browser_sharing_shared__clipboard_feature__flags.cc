$NetBSD$

--- chrome/browser/sharing/shared_clipboard/feature_flags.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/sharing/shared_clipboard/feature_flags.cc
@@ -8,7 +8,7 @@ const base::Feature kSharedClipboardUI{"
                                        base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const base::Feature kRemoteCopyReceiver{"RemoteCopyReceiver",
                                         base::FEATURE_ENABLED_BY_DEFAULT};
 
