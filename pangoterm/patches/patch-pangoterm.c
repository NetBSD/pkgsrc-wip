$NetBSD$

Switch to default off chording.

--- pangoterm.c.orig	2016-03-05 14:25:19.000000000 +0000
+++ pangoterm.c
@@ -54,9 +54,9 @@ CONF_BOOL(doubleclick_fullword, 0, FALSE
 
 CONF_STRING(geometry, 0, "", "Initial window geometry", "GEOM");
 
-CONF_BOOL(chord_shift_space,     0, TRUE, "Shift-Space chording");
-CONF_BOOL(chord_shift_backspace, 0, TRUE, "Shift-Backspace chording");
-CONF_BOOL(chord_shift_enter,     0, TRUE, "Shift-Enter chording");
+CONF_BOOL(chord_shift_space,     0, FALSE, "Shift-Space chording");
+CONF_BOOL(chord_shift_backspace, 0, FALSE, "Shift-Backspace chording");
+CONF_BOOL(chord_shift_enter,     0, FALSE, "Shift-Enter chording");
 
 #define VTERM_COLOR_FROM_GDK_COLOR(c) \
   ((VTermColor){ .red = (c).red / 257, .green = (c).green / 257, .blue = (c).blue / 257 })
