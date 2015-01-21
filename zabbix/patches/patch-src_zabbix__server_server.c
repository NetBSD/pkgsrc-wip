$NetBSD: patch-src_zabbix__server_server.c,v 1.1 2015/01/21 22:56:43 heidnes Exp $

Move PID dirs and use @PREFIX@ for fping / fping6.

--- src/zabbix_server/server.c.orig	2014-11-05 08:01:42.000000000 +0000
+++ src/zabbix_server/server.c
@@ -333,7 +333,7 @@ static void	zbx_set_defaults(void)
 		CONFIG_SNMPTRAP_FILE = zbx_strdup(CONFIG_SNMPTRAP_FILE, "/tmp/zabbix_traps.tmp");
 
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/tmp/zabbix_server.pid");
+		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "@PIDDIR@/zabbix_server.pid");
 
 	if (NULL == CONFIG_ALERT_SCRIPTS_PATH)
 		CONFIG_ALERT_SCRIPTS_PATH = zbx_strdup(CONFIG_ALERT_SCRIPTS_PATH, DATADIR "/zabbix/alertscripts");
@@ -345,10 +345,10 @@ static void	zbx_set_defaults(void)
 		CONFIG_TMPDIR = zbx_strdup(CONFIG_TMPDIR, "/tmp");
 
 	if (NULL == CONFIG_FPING_LOCATION)
-		CONFIG_FPING_LOCATION = zbx_strdup(CONFIG_FPING_LOCATION, "/usr/sbin/fping");
+		CONFIG_FPING_LOCATION = zbx_strdup(CONFIG_FPING_LOCATION, "@PREFIX@/fping");
 #ifdef HAVE_IPV6
 	if (NULL == CONFIG_FPING6_LOCATION)
-		CONFIG_FPING6_LOCATION = zbx_strdup(CONFIG_FPING6_LOCATION, "/usr/sbin/fping6");
+		CONFIG_FPING6_LOCATION = zbx_strdup(CONFIG_FPING6_LOCATION, "@PREFIX@/fping6");
 #endif
 	if (NULL == CONFIG_EXTERNALSCRIPTS)
 		CONFIG_EXTERNALSCRIPTS = zbx_strdup(CONFIG_EXTERNALSCRIPTS, DATADIR "/zabbix/externalscripts");
