$NetBSD: patch-al,v 1.3 2014/06/23 22:24:24 christos Exp $

--- ckuath.c.orig	2020-10-08 19:37:25.000000000 +0000
+++ ckuath.c
@@ -5476,7 +5476,11 @@ k5_auth_is(how,data,cnt) int how; unsign
         if ((how & AUTH_HOW_MASK) == AUTH_HOW_MUTUAL) {
             /* do ap_rep stuff here */
             if ((r = krb5_mk_rep(k5_context,
+#ifdef HEIMDAL
+                                  &auth_context,
+#else /* HEIMDAL */
                                   auth_context,
+#endif /* HEIMDAL */
                                   &outbuf))) {
                 debug(F111,"k5_auth_is","krb5_mk_rep",r);
                 (void) ckstrncpy(errbuf, "Make reply failed: ",sizeof(errbuf));
