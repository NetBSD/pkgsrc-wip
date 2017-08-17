$NetBSD$

Avoid a possible NULL pointer dereference when mhical does not receive any input
(e.g. calling it via `mhical < /dev/null').

--- uip/mhical.c.orig	2017-08-02 03:50:07.000000000 +0000
+++ uip/mhical.c
@@ -714,7 +714,7 @@ display (FILE *file, contentline *clines
     }
 
     /* Don't call on the END:VCALENDAR line. */
-    if (clines->next) {
+    if (clines  &&  clines->next) {
       (void) fmt_scan (fmt, buffer, INT_MAX, dat, NULL);
       fputs (charstring_buffer (buffer), file);
       fmt_free (fmt, 1);
