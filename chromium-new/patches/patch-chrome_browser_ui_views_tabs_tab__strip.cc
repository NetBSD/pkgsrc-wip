$NetBSD$

--- chrome/browser/ui/views/tabs/tab_strip.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_strip.cc
@@ -323,7 +323,7 @@ NewTabButton::NewTabButton(TabStrip* tab
     : views::ImageButton(listener),
       tab_strip_(tab_strip),
       destroyed_(NULL) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   set_triggerable_event_flags(triggerable_event_flags() |
                               ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
