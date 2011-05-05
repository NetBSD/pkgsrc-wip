$NetBSD: patch-Config.h,v 1.1.1.1 2011/05/05 13:07:00 ishit Exp $

--- Config.h.orig	2009-01-09 11:18:03.000000000 +0000
+++ Config.h
@@ -95,7 +95,7 @@ private:
 // middle-button menu
 #define CONFIG_COMMAND_MENU       ".wmx"
 // only used if COMMAND_MENU is not found; ignored if invalid directory:
-#define CONFIG_SYSTEM_COMMAND_MENU	"/usr/local/lib/wmx/menu"
+#define CONFIG_SYSTEM_COMMAND_MENU	PREFIX "/etc/wmx/menu"
 // append screennumber to COMMAND_MENU directory;
 // use non screen style as fallback
 #define CONFIG_ADD_SCREEN_TO_COMMAND_MENU False
@@ -407,7 +407,9 @@ private:
 // command menu, and the middle mouse button (button2)
 // acts like the left mouse normally does (list of windows)
 
+#ifndef CONFIG_GNOME_BUTTON_COMPLIANCE
 #define CONFIG_GNOME_BUTTON_COMPLIANCE   False
+#endif
 
 #endif
 
