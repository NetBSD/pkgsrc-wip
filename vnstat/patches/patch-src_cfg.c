$NetBSD$

Avoid a nonsensical config file path that would result after munging
/etc/ to PKG_SYSCONFDIR.

--- src/cfg.c.orig	2025-01-08 23:15:52.000000000 +0200
+++ src/cfg.c	2026-04-05 21:55:29.559610294 +0300
@@ -484,8 +484,6 @@
 			strncpy_nt(cfg.cfgfile, buffer, 512);
 		} else if ((*fd = fopen("/etc/vnstat.conf", "r")) != NULL) {
 			snprintf(cfg.cfgfile, 512, "/etc/vnstat.conf");
-		} else if ((*fd = fopen("/usr/local/etc/vnstat.conf", "r")) != NULL) {
-			snprintf(cfg.cfgfile, 512, "/usr/local/etc/vnstat.conf");
 		} else {
 			if (debug)
 				printf("Config file: none\n");
