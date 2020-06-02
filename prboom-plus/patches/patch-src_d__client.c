$NetBSD$

Fix heap buffer overflows in UDP code (CVE-2019-20797)
Backported from:
https://github.com/coelckers/prboom-plus/commit/1a081d10e6c71a5b5b2db76081227677f06b47b3

--- src/d_client.c.orig	2014-05-20 04:47:44.000000000 +0000
+++ src/d_client.c
@@ -353,7 +353,8 @@ void NetUpdate(void)
       int sendtics;
       remotesend -= xtratics;
       if (remotesend < 0) remotesend = 0;
-      sendtics = maketic - remotesend;
+/*      sendtics = maketic - remotesend; */
+      sendtics = MIN(maketic - remotesend, 128); // limit number of sent tics (CVE-2019-20797)
       {
   size_t pkt_size = sizeof(packet_header_t) + 2 + sendtics * sizeof(ticcmd_t);
   packet_header_t *packet = Z_Malloc(pkt_size, PU_STATIC, NULL);
