$NetBSD: patch-chrome_browser_ui_views_frame_browser__view.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/frame/browser_view.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -4,7 +4,7 @@
 
 #include "chrome/browser/ui/views/frame/browser_view.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include <gtk/gtk.h>
 #endif
 
@@ -87,7 +87,7 @@
 #include "chrome/browser/aeropeek_manager.h"
 #include "chrome/browser/jumplist_win.h"
 #include "ui/base/view_prop.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_USES_GTK)
 #include "chrome/browser/ui/views/accelerator_table_gtk.h"
 #include "views/window/hit_test.h"
 #include "views/window/window_gtk.h"
@@ -1145,7 +1145,7 @@ void BrowserView::ShowProfileErrorDialog
   string16 message = l10n_util::GetStringUTF16(message_id);
   app::win::MessageBox(GetNativeHandle(), message, title,
                        MB_OK | MB_ICONWARNING | MB_TOPMOST);
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_USES_GTK)
   std::string title = l10n_util::GetStringUTF8(IDS_PRODUCT_NAME);
   std::string message = l10n_util::GetStringUTF8(message_id);
   GtkWidget* dialog = gtk_message_dialog_new(GetNativeHandle(),
@@ -1239,7 +1239,7 @@ bool BrowserView::PreHandleKeyboardEvent
   views::FocusManager* focus_manager = GetFocusManager();
   DCHECK(focus_manager);
 
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if defined(TOOLKIT_USES_GTK) && !defined(TOUCH_UI)
   // Views and WebKit use different tables for GdkEventKey -> views::KeyEvent
   // conversion. We need to use View's conversion table here to keep consistent
   // behavior with views::FocusManager::OnKeyEvent() method.
@@ -1286,7 +1286,7 @@ bool BrowserView::PreHandleKeyboardEvent
     return false;
 
   // Executing the command may cause |this| object to be destroyed.
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if defined(TOOLKIT_USES_GTK) && !defined(TOUCH_UI)
   if (browser_->IsReservedCommand(id) && !event.match_edit_command) {
 #else
   if (browser_->IsReservedCommand(id)) {
@@ -1302,7 +1302,7 @@ bool BrowserView::PreHandleKeyboardEvent
 }
 
 void BrowserView::HandleKeyboardEvent(const NativeWebKeyboardEvent& event) {
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if defined(TOOLKIT_USES_GTK) && !defined(TOUCH_UI)
   views::Window* window = GetWidget()->GetWindow();
   if (window && event.os_event && !event.skip_in_browser)
     static_cast<views::WindowGtk*>(window)->HandleKeyboardEvent(event.os_event);
@@ -2245,7 +2245,7 @@ void BrowserView::ProcessFullscreen(bool
 #endif  // No need to invoke SetFullscreen for linux as this code is executed
         // once we're already fullscreen on linux.
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   // Updating of commands for fullscreen mode is called from SetFullScreen on
   // Wndows (see just above), but for ChromeOS, this method (ProcessFullScreen)
   // is called after full screen has happened successfully (via GTK's
