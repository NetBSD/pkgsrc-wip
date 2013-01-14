$NetBSD: patch-gui_base_locale__util.cc,v 1.1 2013/01/14 14:00:55 ryo-on Exp $

--- gui/base/locale_util.cc.orig	2012-08-31 05:37:21.000000000 +0000
+++ gui/base/locale_util.cc
@@ -206,7 +206,7 @@ TranslationDataImpl::TranslationDataImpl
   qApp->installEventFilter(&window_title_modifier_);
 #endif  // MOZC_SHOW_BUILD_NUMBER_ON_TITLE
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Use system default messages.
   // Even if the locale is not English nor Japanese, load translation
   // file to translate common messages like "OK" and "Cancel".
