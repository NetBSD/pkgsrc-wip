$NetBSD: patch-configuration.c,v 1.1 2012/08/15 11:10:16 fhajny Exp $

SunOS fixes as per https://github.com/bumptech/stud/pull/71.
--- configuration.c.orig	2012-08-15 10:33:39.000000000 +0000
+++ configuration.c
@@ -538,10 +538,10 @@ void config_param_validate (char *k, cha
   struct stat st;
 
   if (strcmp(k, "tls") == 0) {
-    //cfg->ENC_TLS = 1;
+    cfg->ETYPE = ENC_TLS;
   }
   else if (strcmp(k, "ssl") == 0) {
-    //cfg->ENC_TLS = 0;
+    cfg->ETYPE = ENC_SSL;
   }
   else if (strcmp(k, CFG_CIPHERS) == 0) {
     if (v != NULL && strlen(v) > 0) {
@@ -637,13 +637,23 @@ void config_param_validate (char *k, cha
   else if (strcmp(k, CFG_SYSLOG_FACILITY) == 0) {
     r = 1;
     if (!strcmp(v, "auth") || !strcmp(v, "authpriv"))
+#ifdef LOG_AUTHPRIV
       cfg->SYSLOG_FACILITY = LOG_AUTHPRIV;
+#else
+      cfg->SYSLOG_FACILITY = LOG_AUTH;
+#endif
     else if (!strcmp(v, "cron"))
       cfg->SYSLOG_FACILITY = LOG_CRON;
     else if (!strcmp(v, "daemon"))
       cfg->SYSLOG_FACILITY = LOG_DAEMON;
+#ifdef LOG_FTP
     else if (!strcmp(v, "ftp"))
       cfg->SYSLOG_FACILITY = LOG_FTP;
+#endif
+#ifdef LOG_AUDIT
+    else if (!strcmp(v, "audit"))
+      cfg->SYSLOG_FACILITY = LOG_AUDIT;
+#endif
     else if (!strcmp(v, "local0"))
       cfg->SYSLOG_FACILITY = LOG_LOCAL0;
     else if (!strcmp(v, "local1"))
@@ -813,14 +823,25 @@ char * config_disp_hostport (char *host,
 const char * config_disp_log_facility (int facility) {
   switch (facility)
   {
+#ifdef LOG_AUTHPRIV
     case LOG_AUTHPRIV:
       return "authpriv";
+#else
+    case LOG_AUTH:
+      return "auth";
+#endif
     case LOG_CRON:
       return "cron";
     case LOG_DAEMON:
       return "daemon";
+#ifdef LOG_FTP
     case LOG_FTP:
       return "ftp";
+#endif
+#ifdef LOG_AUDIT
+    case LOG_AUDIT:
+      return "audit";
+#endif
     case LOG_LOCAL0:
       return "local0";
     case LOG_LOCAL1:
