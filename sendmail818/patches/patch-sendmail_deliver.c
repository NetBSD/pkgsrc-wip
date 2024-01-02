$NetBSD: patch-as,v 1.2 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/deliver.c.orig	2023-10-30 04:14:01.000000000 +0000
+++ sendmail/deliver.c
@@ -31,6 +31,10 @@ SM_RCSID("@(#)$Id: deliver.c,v 8.1030 20
 # include "tls.h"
 #endif
 
+#if NAMED_BIND
+extern struct __res_state sm_res;
+#endif
+
 #if !_FFR_DMTRIGGER
 static int	deliver __P((ENVELOPE *, ADDRESS *));
 #endif
@@ -2397,7 +2401,7 @@ deliver(e, firstto)
 
 #if NAMED_BIND
 	if (ConfigLevel < 2)
-		_res.options &= ~(RES_DEFNAMES | RES_DNSRCH);	/* XXX */
+		sm_res.options &= ~(RES_DEFNAMES | RES_DNSRCH);	/* XXX */
 #endif
 
 	if (tTd(11, 1))
@@ -4466,7 +4470,7 @@ do_transfer:
 	}
 #if NAMED_BIND
 	if (ConfigLevel < 2)
-		_res.options |= RES_DEFNAMES | RES_DNSRCH;	/* XXX */
+		sm_res.options |= RES_DEFNAMES | RES_DNSRCH;	/* XXX */
 #endif
 
 	if (tTd(62, 1))
@@ -6985,7 +6989,7 @@ hostsignature(m, host, ad, pqflags)
 	char *hp;
 	char *endp;
 	char *lstr;
-	int oldoptions = _res.options;
+	int oldoptions = sm_res.options;
 	char *mxhosts[MAXMXHOSTS + 1];
 	unsigned short mxprefs[MAXMXHOSTS + 1];
 #endif /* NAMED_BIND */
@@ -7058,7 +7062,7 @@ hostsignature(m, host, ad, pqflags)
 
 #if NAMED_BIND
 	if (ConfigLevel < 2)
-		_res.options &= ~(RES_DEFNAMES | RES_DNSRCH);	/* XXX */
+		sm_res.options &= ~(RES_DEFNAMES | RES_DNSRCH);	/* XXX */
 
 	for (hp = host; hp != NULL; hp = endp)
 	{
@@ -7218,7 +7222,7 @@ hostsignature(m, host, ad, pqflags)
 	lstr = makelower_a(&s->s_hostsig.hs_sig, NULL);
 	ASSIGN_IFDIFF(s->s_hostsig.hs_sig, lstr);
 	if (ConfigLevel < 2)
-		_res.options = oldoptions;
+		sm_res.options = oldoptions;
 #else /* NAMED_BIND */
 	/* not using BIND -- the signature is just the host name */
 	/*
