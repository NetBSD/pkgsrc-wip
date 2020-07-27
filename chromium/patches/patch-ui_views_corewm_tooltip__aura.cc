$NetBSD$

--- ui/views/corewm/tooltip_aura.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ ui/views/corewm/tooltip_aura.cc
@@ -46,7 +46,7 @@ constexpr int kVerticalPaddingBottom = 5
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_WIN)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)) || defined(OS_WIN)
   return false;
 #else
   return true;
