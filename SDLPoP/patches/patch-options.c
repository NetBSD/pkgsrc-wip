$NetBSD$

Use installed data path.
Disable rumble/haptic support.

--- src/options.c.orig	2018-03-17 16:33:14.000000000 +0000
+++ src/options.c
@@ -185,7 +185,8 @@ static int global_ini_callback(const cha
 		process_boolean("use_correct_aspect_ratio", &use_correct_aspect_ratio);
 		process_boolean("use_integer_scaling", &use_integer_scaling);
 		process_byte("scaling_type", &scaling_type, &scaling_type_names_list);
-		process_boolean("enable_controller_rumble", &enable_controller_rumble);
+		// process_boolean("enable_controller_rumble", &enable_controller_rumble);
+		enable_controller_rumble = 0;
 		process_boolean("joystick_only_horizontal", &joystick_only_horizontal);
 		process_int("joystick_threshold", &joystick_threshold, NULL);
 
@@ -436,7 +437,7 @@ void set_options_to_default() {
 
 void load_global_options() {
 	set_options_to_default();
-	ini_load(locate_file("SDLPoP.ini"), global_ini_callback); // global configuration
+	ini_load(PKGSRC_DATA_PATH "SDLPoP.ini", global_ini_callback); // global configuration
 }
 
 void check_mod_param() {
