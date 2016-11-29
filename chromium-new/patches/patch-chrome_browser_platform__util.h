$NetBSD$

--- chrome/browser/platform_util.h.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/platform_util.h
@@ -40,7 +40,7 @@ enum OpenOperationResult {
 enum OpenItemType {
   OPEN_FILE,
   OPEN_FOLDER,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SHOW_ITEM_IN_FOLDER
 #endif
 };
