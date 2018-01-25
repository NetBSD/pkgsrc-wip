$NetBSD$

tor -> tordev.

--- src/or/config.c.orig	2018-01-24 17:04:12.000000000 +0000
+++ src/or/config.c
@@ -359,9 +359,9 @@ static config_var_t option_vars_[] = {
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
@@ -7769,7 +7769,7 @@ get_data_directory(const char *val)
                "\"%s\", which is probably not what you want.  Using "
                "\"%s"PATH_SEPARATOR"tor\" instead", fn, LOCALSTATEDIR);
       tor_free(fn);
-      fn = tor_strdup(LOCALSTATEDIR PATH_SEPARATOR "tor");
+      fn = tor_strdup(LOCALSTATEDIR PATH_SEPARATOR "tordev");
     }
     return fn;
   }
