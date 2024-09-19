$NetBSD$

--- library/tests/frob-list-modified.c.orig	2018-07-24 17:00:13.000000000 +0000
+++ library/tests/frob-list-modified.c
@@ -57,7 +57,7 @@ main (int argc, char **argv)
 		datetime = g_date_time_new_from_unix_utc (gnome_keyring_item_info_get_mtime (info));
 		date = g_date_time_format (datetime, "%Y%m%dT%H%M%S");
 		display = gnome_keyring_item_info_get_display_name (info);
-		g_print ("%lu %s: %s/%u: %s\n", gnome_keyring_item_info_get_mtime (info),
+		g_print ("%llu %s: %s/%u: %s\n", gnome_keyring_item_info_get_mtime (info),
 		         date, found->keyring, found->item_id, display);
 		g_date_time_unref (datetime);
 		g_free (date);
