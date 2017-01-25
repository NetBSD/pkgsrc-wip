$NetBSD$

Avoid using Linux-specific headers when not compiling for Linux.

--- src/xlib/main.c.orig	2017-01-16 21:01:20.000000000 +0000
+++ src/xlib/main.c
@@ -38,7 +38,9 @@ void postmessage_utox(UTOX_MSG msg, uint
     XFlush(display);
 }
 
+#ifdef __linux__
 #include <linux/input.h>
+#endif
 FILE    *ptt_keyboard_handle;
 Display *ptt_display;
 void     init_ptt(void) {
@@ -63,6 +65,7 @@ bool check_ptt_key(void) {
     int ptt_key;
 
     /* First, we try for direct access to the keyboard. */
+#ifdef __linux__
     ptt_key = KEY_LEFTCTRL; // TODO allow user to change this...
     if (ptt_keyboard_handle) {
         /* Nice! we have direct access to the keyboard! */
@@ -79,6 +82,7 @@ bool check_ptt_key(void) {
             return 0;
         }
     }
+#endif
     /* Okay nope, lets' fallback to xinput... *pouts*
      * Fall back to Querying the X for the current keymap. */
     ptt_key       = XKeysymToKeycode(display, XK_Control_L);
