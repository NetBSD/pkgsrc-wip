$NetBSD$

--- ui/views/style/platform_style.cc.orig	2016-06-24 01:02:54.000000000 +0000
+++ ui/views/style/platform_style.cc
@@ -55,7 +55,7 @@ scoped_ptr<ScrollBar> PlatformStyle::Cre
 }
 #endif
 
-#if !defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 // static
 scoped_ptr<Border> PlatformStyle::CreateThemedLabelButtonBorder(
     LabelButton* button) {
