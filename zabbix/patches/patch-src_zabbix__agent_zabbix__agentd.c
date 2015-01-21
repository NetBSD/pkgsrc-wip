$NetBSD: patch-src_zabbix__agent_zabbix__agentd.c,v 1.1 2015/01/21 22:56:43 heidnes Exp $

Make it possible to tweak the zabbix conf drive/directory on Windows.

--- src/zabbix_agent/zabbix_agentd.c.orig	2014-11-05 08:01:42.000000000 +0000
+++ src/zabbix_agent/zabbix_agentd.c
@@ -57,7 +57,7 @@ const char	*progname = NULL;
 
 /* default config file location */
 #ifdef _WINDOWS
-	static char	DEFAULT_CONFIG_FILE[]	= "C:\\zabbix_agentd.conf";
+	static char	DEFAULT_CONFIG_FILE[]	= "@CONFDIR@\\zabbix_agentd.conf";
 #else
 	static char	DEFAULT_CONFIG_FILE[]	= SYSCONFDIR "/zabbix_agentd.conf";
 #endif
