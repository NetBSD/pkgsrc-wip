$NetBSD: patch-bin__varnishd__mgt_sandbox.c,v 1.1.1.1 2011/07/02 22:32:43 genolopolis Exp $

--- bin/varnishd/mgt_sandbox.c.orig	2011-07-02 22:29:22.000000000 +0000
+++ bin/varnishd/mgt_sandbox.c
@@ -98,6 +98,7 @@ mgt_sandbox(void)
 		 * silently ignore any errors if it doesn't exist
 		 */
 		priv_addset(minimal, "net_access");
+		priv_addset(minimal, "file_read");
 
 #define SETPPRIV(which, set)						\
 		if (setppriv(PRIV_SET, which, set))			\
