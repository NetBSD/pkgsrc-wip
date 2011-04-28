$NetBSD: patch-chrome_browser_ui_views_find__bar__view.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/find_bar_view.h.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/find_bar_view.h
@@ -125,7 +125,7 @@ class FindBarView : public DropdownBarVi
   // between us and the TabContentsView.
   FindBarHost* find_bar_host() const;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // In GTK we get changed signals if we programmatically set the text. If we
   // don't ignore them we run into problems. For example, switching tabs back
   // to one with the find bar visible will cause a search to the next found
