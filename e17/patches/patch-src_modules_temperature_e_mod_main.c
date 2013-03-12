$NetBSD: patch-src_modules_temperature_e_mod_main.c,v 1.1 2013/03/12 07:54:06 roelants Exp $

Explicitly exec tempget, so this process is parent of it, not of
the shell that is used to start it.

--- src/modules/temperature/e_mod_main.c
+++ src/modules/temperature/e_mod_main.c
@@ -321,7 +321,7 @@ temperature_face_update_config(Config_Face *inst)
 	if (!inst->tempget_exe) 
 	  {
 	     snprintf(buf, sizeof(buf),
-		      "%s/%s/tempget %i \"%s\" %i", 
+		      "exec %s/%s/tempget %i \"%s\" %i", 
 		      e_module_dir_get(temperature_config->module), MODULE_ARCH, 
 		      inst->sensor_type,
 		      (inst->sensor_name ? inst->sensor_name : "(null)"),
@@ -349,7 +349,7 @@ temperature_face_update_config(Config_Face *inst)
    if (!inst->tempget_exe) 
      {
 	snprintf(buf, sizeof(buf),
-		 "%s/%s/tempget %i \"%s\" %i", 
+		 "exec %s/%s/tempget %i \"%s\" %i", 
 		 e_module_dir_get(temperature_config->module), MODULE_ARCH, 
 		 inst->sensor_type,
 		 (inst->sensor_name ? inst->sensor_name : "(null)"),
