$NetBSD: patch-daemon_auth-ip.c,v 1.1 2013/10/18 10:16:13 fhajny Exp $

Use proper sysconfdir.
--- daemon/auth-ip.c.orig	2013-03-25 05:01:02.000000000 +0000
+++ daemon/auth-ip.c
@@ -95,8 +95,8 @@ void ip_init(void)
         if (NULL != (fp = fopen("./spread.access_ip", "r")) )
             Alarmp( SPLOG_INFO, ACM, "ip_init: using file: ./spread.access_ip\n");
     if (fp == NULL)
-        if (NULL != (fp = fopen("/etc/spread.access_ip", "r")) )
-            Alarmp( SPLOG_INFO, ACM, "ip_init: using file: /etc/spread.access_ip\n");
+        if (NULL != (fp = fopen(SPREAD_ETCDIR "/spread.access_ip", "r")) )
+            Alarmp( SPLOG_INFO, ACM, "ip_init: using file: " SPREAD_ETCDIR "/spread.access_ip\n");
     if (fp == NULL)
     {
         Alarmp( SPLOG_ERROR, ACM, "ip_init: IP access control file not found.\nIf you are using IP based access controls, please make sure the file exists.\n");
