$NetBSD: patch-darwin.c,v 1.1 2014/01/03 05:31:52 othyro Exp $

Fix casting errors.

--- darwin.c.orig	2013-04-14 17:19:41.000000000 +0000
+++ darwin.c
@@ -79,7 +79,7 @@ sockwant(Socket *s, int rw)
             ev->data = Infinity;
         }
         ev->flags = EV_ADD;
-        ev->udata = s;
+        ev->udata = (intptr_t) s;
         s->added = ev->filter;
         ev++;
         n++;
@@ -105,7 +105,7 @@ socknext(Socket **s, int64 timeout)
     }
 
     if (r > 0) {
-        *s = ev.udata;
+        *s = (Socket *) ev.udata;
         if (ev.flags & EV_EOF) {
             return 'h';
         }
