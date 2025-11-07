$NetBSD$

Fix build with libplist-2.7.0. Already fixed in upstream.

--- src/conf.c.orig	2025-11-07 10:41:30.750835727 +0000
+++ src/conf.c
@@ -230,7 +230,7 @@ static int internal_set_value(const char
 	/* read file into plist */
 	plist_t config = NULL;
 
-	plist_read_from_filename(&config, config_file);
+	plist_read_from_file(config_file, &config, NULL);
 	if (!config) {
 		config = plist_new_dict();
 		plist_dict_set_item(config, key, value);
@@ -254,7 +254,7 @@ static int internal_set_value(const char
 		usbmuxd_log(LL_DEBUG, "Setting key %s in config file %s", key, config_file);
 	}
 
-	int res = plist_write_to_filename(config, config_file, PLIST_FORMAT_XML);
+	int res = plist_write_to_file(config, config_file, PLIST_FORMAT_XML, 0);
 
 	plist_free(config);
 
@@ -288,7 +288,7 @@ static int internal_get_value(const char
 
 	/* now parse file to get the SystemBUID */
 	plist_t config = NULL;
-	if (plist_read_from_filename(&config, config_file)) {
+	if (plist_read_from_file(config_file, &config, NULL)) {
 		usbmuxd_log(LL_DEBUG, "Reading key %s from config file %s", key, config_file);
 		plist_t n = plist_dict_get_item(config, key);
 		if (n) {
@@ -428,7 +428,7 @@ int config_set_device_record(const char 
 	remove(device_record_file);
 
 	/* store file */
-	if (!plist_write_to_filename(plist, device_record_file, PLIST_FORMAT_XML)) {
+	if (!plist_write_to_file(plist, device_record_file, PLIST_FORMAT_XML, 0)) {
 		usbmuxd_log(LL_DEBUG, "Could not open '%s' for writing: %s", device_record_file, strerror(errno));
 		res = -ENOENT;
 	}
