$NetBSD: patch-at,v 1.2 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/domain.c.orig	2023-07-24 18:49:57.000000000 +0000
+++ sendmail/domain.c
@@ -23,6 +23,9 @@ SM_RCSID("@(#)$Id: domain.c,v 8.205 2013
 #include <sm/sendmail.h>
 
 #if NAMED_BIND
+
+extern struct __res_state sm_res;
+
 # include <arpa/inet.h>
 # include "sm_resolve.h"
 # if DANE
@@ -51,7 +54,7 @@ static char	MXHostBuf[MXHOSTBUFSIZE];
 # endif
 
 # ifndef RES_DNSRCH_VARIABLE
-#  define RES_DNSRCH_VARIABLE	_res.dnsrch
+#  define RES_DNSRCH_VARIABLE	sm_res.dnsrch
 # endif
 
 # ifndef HFIXEDSZ
@@ -909,9 +912,9 @@ getmxrr(host, mxhosts, mxprefs, flags, r
 # if DANE
 	cname2mx = false;
 	qname[0] = '\0';
-	old_options = _res.options;
+	old_options = sm_res.options;
 	if (ad)
-		_res.options |= SM_RES_DNSSEC;
+		sm_res.options |= SM_RES_DNSSEC;
 # endif
 
 	if ((fallbackMX != NULL && (flags & DROPLOCALHOST) != 0 &&
@@ -1072,7 +1075,7 @@ getmxrr(host, mxhosts, mxprefs, flags, r
 # endif
 		if (type != T_MX)
 		{
-			if ((tTd(8, 8) || _res.options & RES_DEBUG)
+			if ((tTd(8, 8) || sm_res.options & RES_DEBUG)
 # if DANE
 			    && type != T_RRSIG
 # endif
@@ -1410,13 +1413,13 @@ punt:
 	}
     done:
 # if DANE
-	_res.options = old_options;
+	sm_res.options = old_options;
 # endif
 	return nmx;
 
    error:
 # if DANE
-	_res.options = old_options;
+	sm_res.options = old_options;
 # endif
 	return -1;
 }
@@ -1486,7 +1489,7 @@ bestmx_map_lookup(map, name, av, statp)
 	int *statp;
 {
 	int nmx;
-	int saveopts = _res.options;
+	int saveopts = sm_res.options;
 	int i;
 	ssize_t len = 0;
 	char *result;
@@ -1498,9 +1501,9 @@ bestmx_map_lookup(map, name, av, statp)
 	char buf[PSBUFSIZE / 2];
 # endif
 
-	_res.options &= ~(RES_DNSRCH|RES_DEFNAMES);
+	sm_res.options &= ~(RES_DNSRCH|RES_DEFNAMES);
 	nmx = getmxrr(name, mxhosts, NULL, 0, statp, NULL, -1, NULL);
-	_res.options = saveopts;
+	sm_res.options = saveopts;
 	if (nmx <= 0)
 		return NULL;
 	if (bitset(MF_MATCHONLY, map->map_mflags))
@@ -1650,16 +1653,22 @@ dns_getcanonname(host, hbsize, trymx, st
 	if (tTd(8, 2))
 		sm_dprintf("dns_getcanonname(%s, trymx=%d)\n", host, trymx);
 
-	if ((_res.options & RES_INIT) == 0 && res_init() == -1)
-	{
-		*statp = EX_UNAVAILABLE;
-		return HOST_NOTFOUND;
+	if ((sm_res.options & RES_INIT) == 0) {
+# if NAMED_RESN
+		memset(&sm_res, 0, sizeof(sm_res));
+		if (res_ninit(&sm_res) == -1) {
+# else
+		if (res_init() == -1) {
+# endif
+			*statp = EX_UNAVAILABLE;
+			return false;
+		}
 	}
 
 # if DANE
-	old_options = _res.options;
+	old_options = sm_res.options;
 	if (DANE_SECURE == Dane)
-		_res.options |= SM_RES_DNSSEC;
+		sm_res.options |= SM_RES_DNSSEC;
 # endif
 
 	*statp = EX_OK;
@@ -1709,7 +1718,7 @@ cnameloop:
 		searchlist[sli++] = NameSearchList;
 	}
 # endif
-	if (n >= 0 && *--cp != '.' && bitset(RES_DNSRCH, _res.options))
+	if (n >= 0 && *--cp != '.' && bitset(RES_DNSRCH, sm_res.options))
 	{
 		/* make sure there are less than MAXDNSRCH domains */
 		for (domain = RES_DNSRCH_VARIABLE, ret = 0;
@@ -1717,10 +1726,10 @@ cnameloop:
 		     ret++)
 			searchlist[sli++] = *domain++;
 	}
-	else if (n == 0 && bitset(RES_DEFNAMES, _res.options))
+	else if (n == 0 && bitset(RES_DEFNAMES, sm_res.options))
 	{
 		SM_ASSERT(sli < SLSIZE);
-		searchlist[sli++] = _res.defdname;
+		searchlist[sli++] = sm_res.defdname;
 	}
 	else if (*cp == '.')
 	{
@@ -2026,13 +2035,13 @@ nexttype:
 	if (ttl > 0 && pttl != NULL)
 		*pttl = ttl;
 # if DANE
-	_res.options = old_options;
+	sm_res.options = old_options;
 # endif
 	return ad ? HOST_SECURE : HOST_OK;
 
   error:
 # if DANE
-	_res.options = old_options;
+	sm_res.options = old_options;
 # endif
 	return HOST_NOTFOUND;
 }
