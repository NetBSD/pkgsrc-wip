$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/task_manager_search_bar_view.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/views/task_manager_search_bar_view.cc
@@ -27,7 +27,7 @@ TaskManagerSearchBarView::TaskManagerSea
     const gfx::Insets& margins,
     Delegate& delegate)
     : delegate_(delegate)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       ,
       textfield_placeholder_color_id_(kColorTaskManagerSearchBarPlaceholderText)
 #endif
