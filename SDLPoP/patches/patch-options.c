$NetBSD$

Use installed data path.
Disable rumble/haptic support.

--- src/options.c.orig	2017-02-05 07:38:56.000000000 +0000
+++ src/options.c
@@ -207,7 +207,8 @@ static int global_ini_callback(const cha
 		process_word("pop_window_width", &pop_window_width, NULL);
 		process_word("pop_window_height", &pop_window_height, NULL);
 		process_boolean("use_correct_aspect_ratio", &use_correct_aspect_ratio);
-        process_boolean("enable_controller_rumble", &enable_controller_rumble);
+        // process_boolean("enable_controller_rumble", &enable_controller_rumble);
+        enable_controller_rumble = 0;
         process_boolean("joystick_only_horizontal", &joystick_only_horizontal);
 
         if (strcasecmp(name, "levelset") == 0) {
@@ -369,7 +370,7 @@ static int mod_ini_callback(const char *
 }
 
 void load_global_options() {
-    ini_load("SDLPoP.ini", global_ini_callback); // global configuration
+    ini_load(PKGSRC_DATA_PATH "SDLPoP.ini", global_ini_callback); // global configuration
 }
 
 void check_mod_param() {
