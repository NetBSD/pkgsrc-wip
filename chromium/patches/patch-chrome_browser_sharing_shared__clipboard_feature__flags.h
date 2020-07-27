$NetBSD$

--- chrome/browser/sharing/shared_clipboard/feature_flags.h.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/sharing/shared_clipboard/feature_flags.h
@@ -15,7 +15,7 @@
 extern const base::Feature kSharedClipboardUI;
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 // Feature to enable handling remote copy messages.
 extern const base::Feature kRemoteCopyReceiver;
 
