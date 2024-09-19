$NetBSD$

Continue gracefully if no joystick driver is available.

Currently needed on e.g. NetBSD. TODO: Fix this by adding NetBSD HID
support to allegro.

--- src/core/input.c.orig	2021-01-25 19:29:44.000000000 +0000
+++ src/core/input.c
@@ -126,9 +126,8 @@ void input_init()
         fatal_error("Can't initialize the mouse");
     al_register_event_source(a5_event_queue, al_get_mouse_event_source());
 
-    if(!al_install_joystick())
-        fatal_error("Can't initialize the joystick subsystem");
-    al_register_event_source(a5_event_queue, al_get_joystick_event_source());
+    if(al_install_joystick())
+        al_register_event_source(a5_event_queue, al_get_joystick_event_source());
 
     /* joystick config */
     if(input_is_joystick_available()) {
@@ -832,4 +831,4 @@ bool are_all_joysticks_valid()
 
     return true;
 }
-#endif
\ No newline at end of file
+#endif
