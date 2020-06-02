$NetBSD$

Fix heap buffer overflows in UDP code (CVE-2019-20797)
Backported from:
https://github.com/coelckers/prboom-plus/commit/1a081d10e6c71a5b5b2db76081227677f06b47b3

--- src/d_server.c.orig	2014-05-20 04:47:44.000000000 +0000
+++ src/d_server.c
@@ -681,7 +681,8 @@ int main(int argc, char** argv)
       int tics;
       if (lowtic <= remoteticto[i]) continue;
       if ((remoteticto[i] -= xtratics) < 0) remoteticto[i] = 0;
-      tics = lowtic - remoteticto[i];
+/*      tics = lowtic - remoteticto[i]; */
+      tics = MIN(lowtic - remoteticto[i], 128); // limit number of sent tics (CVE-2019-20797)
       {
         byte *p;
         packet = malloc(sizeof(packet_header_t) + 1 +
