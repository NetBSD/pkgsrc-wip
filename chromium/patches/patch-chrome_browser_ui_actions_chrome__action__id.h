$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/actions/chrome_action_id.h.orig	2024-07-24 02:44:29.092050600 +0000
+++ chrome/browser/ui/actions/chrome_action_id.h
@@ -515,7 +515,7 @@
     IDC_CONTENT_CONTEXT_QUICK_ANSWERS_INLINE_ANSWER) \
   E(kActionContentContextQuickAnswersInlineQuery, \
     IDC_CONTENT_CONTEXT_QUICK_ANSWERS_INLINE_QUERY)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define CHROME_PLATFORM_SPECIFIC_ACTION_IDS \
   E(kUseSystemTitleBar, IDC_USE_SYSTEM_TITLE_BAR) \
   E(kRestoreWindow, IDC_RESTORE_WINDOW)
