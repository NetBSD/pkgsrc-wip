$NetBSD$

Make sure paths match.

--- src/smsd_cfg.c.orig	2010-09-21 09:15:07.000000000 +0000
+++ src/smsd_cfg.c
@@ -159,12 +159,12 @@ void initcfg()
   log_unmodified = 0;
   alarmlevel=LOG_WARNING;
 
-  strcpy(d_spool,"/var/spool/sms/outgoing");
-  strcpy(d_incoming,"/var/spool/sms/incoming");
+  strcpy(d_spool,SMS_DIR "/outgoing");
+  strcpy(d_incoming,SMS_DIR "/incoming");
   *d_report = 0;
   *d_phonecalls = 0;
   *d_saved = 0;
-  strcpy(d_checked,"/var/spool/sms/checked");
+  strcpy(d_checked,SMS_DIR "/checked");
   d_failed[0]=0;
   d_sent[0]=0;
   d_stats[0]=0;
