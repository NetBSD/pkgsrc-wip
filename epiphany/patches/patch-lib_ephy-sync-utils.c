$NetBSD$

--- lib/ephy-sync-utils.c.orig	2021-03-19 19:44:15.365009000 +0000
+++ lib/ephy-sync-utils.c
@@ -187,6 +187,8 @@ ephy_sync_utils_generate_random_bytes (v
   if (getentropy (out, num_bytes) == -1) {
     g_error ("Failed to get entropy: %s", g_strerror (errno));
   }
+#elif defined(__NetBSD__)
+  arc4random_buf (out, num_bytes); 
 #else
   do {
     ret = getrandom (out, num_bytes, 0);
