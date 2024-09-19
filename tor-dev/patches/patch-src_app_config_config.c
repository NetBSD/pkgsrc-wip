$NetBSD$

tor -> tordev.

--- src/app/config/config.c.orig	2018-09-21 11:51:54.000000000 +0000
+++ src/app/config/config.c
@@ -437,9 +437,9 @@ static config_var_t option_vars_[] = {
   V(GeoIPv6File,                 FILENAME, "<default>"),
 #else
   V(GeoIPFile,                   FILENAME,
-    SHARE_DATADIR PATH_SEPARATOR "tor" PATH_SEPARATOR "geoip"),
+    SHARE_DATADIR PATH_SEPARATOR "tordev" PATH_SEPARATOR "geoip"),
   V(GeoIPv6File,                 FILENAME,
-    SHARE_DATADIR PATH_SEPARATOR "tor" PATH_SEPARATOR "geoip6"),
+    SHARE_DATADIR PATH_SEPARATOR "tordev" PATH_SEPARATOR "geoip6"),
 #endif /* defined(_WIN32) */
   OBSOLETE("Group"),
   V(GuardLifetime,               INTERVAL, "0 minutes"),
