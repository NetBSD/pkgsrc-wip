$NetBSD$

Use proper PKG_SYSCONFDIR.

--- src/smsd_cfg.h.orig	2010-09-20 11:11:26.000000000 +0000
+++ src/smsd_cfg.h
@@ -20,12 +20,7 @@ Either version 2 of the License, or (at
 #include <sys/types.h>
 #include <time.h>
 
-#ifndef __FreeBSD__
-#define DEFAULT_CONFIGFILE "/etc/smsd.conf"
-#else
-#define DEFAULT_CONFIGFILE "%%PREFIX%%/etc/smsd.conf"
-#endif
-
+#define DEFAULT_CONFIGFILE PKG_SYSCONFDIR "/smsd.conf"
 #define DATETIME_DEFAULT "%y-%m-%d %H:%M:%S"
 #define LOGTIME_DEFAULT "%Y-%m-%d %H:%M:%S"
 #define DATE_FILENAME_DEFAULT "%Y-%m-%d"
