$NetBSD$

tor -> tordev.

--- src/or/config.c.orig	2017-11-05 19:09:21.000000000 +0000
+++ src/or/config.c
@@ -349,9 +349,9 @@ static config_var_t option_vars_[] = {
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
@@ -7646,7 +7646,7 @@ normalize_data_directory(or_options_t *o
               "\"%s\", which is probably not what you want.  Using "
               "\"%s"PATH_SEPARATOR"tor\" instead", fn, LOCALSTATEDIR);
      tor_free(fn);
-     fn = tor_strdup(LOCALSTATEDIR PATH_SEPARATOR "tor");
+     fn = tor_strdup(LOCALSTATEDIR PATH_SEPARATOR "tordev");
    }
    tor_free(options->DataDirectory);
    options->DataDirectory = fn;
