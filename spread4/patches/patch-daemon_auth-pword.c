$NetBSD: patch-daemon_auth-pword.c,v 1.1 2013/10/18 10:16:13 fhajny Exp $

Use proper sysconfdir.
--- daemon/auth-pword.c.orig	2013-03-25 05:01:02.000000000 +0000
+++ daemon/auth-pword.c
@@ -123,8 +123,8 @@ void pword_init(void)
         if (NULL != (fp = fopen("./spread.access_pword", "r")) )
             Alarmp( SPLOG_INFO,ACM, "pword_init: using file: ./spread.access_pword\n");
     if (fp == NULL)
-        if (NULL != (fp = fopen("/etc/spread.access_pword", "r")) )
-            Alarmp( SPLOG_INFO, ACM, "pword_init: using file: /etc/spread.access_pword\n");
+        if (NULL != (fp = fopen(SPREAD_ETCDIR "/spread.access_pword", "r")) )
+            Alarmp( SPLOG_INFO, ACM, "pword_init: using file: " SPREAD_ETCDIR "/spread.access_pword\n");
     if (fp == NULL)
         Alarmp( SPLOG_FATAL, ACM, "pword_init: error opening config file %s in any of the standard locations. Please make sure the file exists\n", file_name);
 
