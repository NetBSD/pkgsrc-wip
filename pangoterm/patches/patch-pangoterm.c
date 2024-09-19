$NetBSD$

Switch to default off chording.
Fix build with newer libvterm

--- pangoterm.c.orig	2016-03-05 14:25:19.000000000 +0000
+++ pangoterm.c
@@ -54,15 +54,15 @@ CONF_BOOL(doubleclick_fullword, 0, FALSE
 
 CONF_STRING(geometry, 0, "", "Initial window geometry", "GEOM");
 
-CONF_BOOL(chord_shift_space,     0, TRUE, "Shift-Space chording");
-CONF_BOOL(chord_shift_backspace, 0, TRUE, "Shift-Backspace chording");
-CONF_BOOL(chord_shift_enter,     0, TRUE, "Shift-Enter chording");
+CONF_BOOL(chord_shift_space,     0, FALSE, "Shift-Space chording");
+CONF_BOOL(chord_shift_backspace, 0, FALSE, "Shift-Backspace chording");
+CONF_BOOL(chord_shift_enter,     0, FALSE, "Shift-Enter chording");
 
 #define VTERM_COLOR_FROM_GDK_COLOR(c) \
-  ((VTermColor){ .red = (c).red / 257, .green = (c).green / 257, .blue = (c).blue / 257 })
+  ((VTermColor){ .rgb.red = (c).red / 257, .rgb.green = (c).green / 257, .rgb.blue = (c).blue / 257 })
 
 #define GDK_COLOR_FROM_VTERM_COLOR(c) \
-  ((GdkColor){ .red = 257 * (c).red, .green = 257 * (c).green, .blue = 257 * (c).blue })
+  ((GdkColor){ .red = 257 * (c).rgb.red, .green = 257 * (c).rgb.green, .blue = 257 * (c).rgb.blue })
 
 #ifdef DEBUG
 # define DEBUG_PRINT_INPUT
