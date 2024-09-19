$NetBSD$

Fix buffer overflow (on NetBSD 9.99.74).

--- server/hw/hw_tty_common/driver_termcap.h.orig	2019-12-23 20:33:52.000000000 +0000
+++ server/hw/hw_tty_common/driver_termcap.h
@@ -88,7 +88,7 @@ static udat termcap_LookupKey(udat *Shif
 }
 
 static char *termcap_extract(CONST char *cap, char **dest) {
-  char buf[20], *d = buf, *s = tgetstr(cap, &d);
+  char buf[1024], *d = buf, *s = tgetstr(cap, &d);
 
   if (!s || !*s) {
     return *dest = CloneStr("");
