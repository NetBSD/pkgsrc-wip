$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- x25.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ x25.c
@@ -34,7 +34,7 @@ static struct rr *x25_parse(char *name, 
     if (rr->psdn_address.length < 4)
         return bitch("PSDN-address too short");
     for (i = 0; i < rr->psdn_address.length; i++) {
-        if (!isdigit(rr->psdn_address.data[i]))
+        if (!isdigit((unsigned char)rr->psdn_address.data[i]))
             return bitch("PSDN-address contains non-digits");
     }
 
