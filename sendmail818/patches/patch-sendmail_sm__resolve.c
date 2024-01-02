$NetBSD: patch-ay,v 1.3 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/sm_resolve.c.orig	2023-02-09 18:24:38.000000000 +0000
+++ sendmail/sm_resolve.c
@@ -61,2 +61,6 @@ SM_RCSID("$Id: sm_resolve.c,v 8.40 2013-
 
+#if NAMED_BIND
+extern struct __res_state sm_res;
+#endif
+
 static struct stot
@@ -879,3 +883,3 @@ dnscrtrr(domain, query, qtype, value, rr
 
-			adflag = (_res.options & RES_USE_DNSSEC) != 0;
+			adflag = (sm_res.options & RES_USE_DNSSEC) != 0;
 
@@ -1239,3 +1243,2 @@ dns_lookup_int(domain, rr_class, rr_type
 	unsigned char *reply;
-	int (*resfunc) __P((const char *, int, int, u_char *, int));
 
@@ -1246,10 +1249,4 @@ dns_lookup_int(domain, rr_class, rr_type
 
-	resfunc = res_search;
-#  if DNSSEC_TEST
-	if (tTd(8, 110))
-		resfunc = tstdns_search;
-#  endif
-
-	old_options = _res.options;
-	_res.options |= options;
+	old_options = sm_res.options;
+	sm_res.options |= options;
 	if (err != NULL)
@@ -1260,3 +1257,3 @@ dns_lookup_int(domain, rr_class, rr_type
 	{
-		_res.options |= RES_DEBUG;
+		sm_res.options |= RES_DEBUG;
 		sm_dprintf("dns_lookup_int(%s, %d, %s, %x)\n", domain,
@@ -1267,4 +1264,4 @@ dns_lookup_int(domain, rr_class, rr_type
 		sm_dprintf("NS=%s, port=%d\n",
-			inet_ntoa(_res.nsaddr_list[0].sin_addr),
-			ntohs(_res.nsaddr_list[0].sin_port));
+			inet_ntoa(sm_res.nsaddr_list[0].sin_addr),
+			ntohs(sm_res.nsaddr_list[0].sin_port));
 #  endif
@@ -1272,4 +1269,4 @@ dns_lookup_int(domain, rr_class, rr_type
 	{
-		save_retrans = _res.retrans;
-		_res.retrans = retrans;
+		save_retrans = sm_res.retrans;
+		sm_res.retrans = retrans;
 	}
@@ -1277,4 +1274,4 @@ dns_lookup_int(domain, rr_class, rr_type
 	{
-		save_retry = _res.retry;
-		_res.retry = retry;
+		save_retry = sm_res.retry;
+		sm_res.retry = retry;
 	}
@@ -1283,3 +1280,12 @@ dns_lookup_int(domain, rr_class, rr_type
 	reply = (unsigned char *)&reply_buf;
-	len = (*resfunc)(domain, rr_class, rr_type, reply, SMRBSIZE);
+#  if DNSSEC_TEST
+	if (tTd(8, 110))
+		len = tstdns_search(domain, rr_class, rr_type, reply, SMRBSIZE);
+	else
+#  endif
+#  if NAMED_RESN
+	len = res_nsearch(&sm_res, domain, rr_class, rr_type, reply, SMRBSIZE);
+#  else
+	len = res_search(domain, rr_class, rr_type, reply, SMRBSIZE);
+#  endif
 	if (len >= SMRBSIZE)
@@ -1303,4 +1309,15 @@ dns_lookup_int(domain, rr_class, rr_type
 				SM_SET_H_ERRNO(0);
-				len = (*resfunc)(domain, rr_class, rr_type,
-						 reply, IP_MAXPACKET);
+#  if DNSSEC_TEST
+				if (tTd(8, 110))
+					len = tstdns_search(domain, rr_class,
+					    rr_type, reply, IP_MAXPACKET);
+				else
+#  endif
+#  if NAMED_RESN
+				len = res_nsearch(&sm_res, domain, rr_class,
+				    rr_type, reply, IP_MAXPACKET);
+#  else
+				len = res_search(domain, rr_class, rr_type,
+				    reply, IP_MAXPACKET);
+#  endif
 			}
@@ -1308,3 +1325,3 @@ dns_lookup_int(domain, rr_class, rr_type
 	}
-	_res.options = old_options;
+	sm_res.options = old_options;
 	if (len < 0)
@@ -1344,5 +1361,5 @@ dns_lookup_int(domain, rr_class, rr_type
 	if (retrans > 0)
-		_res.retrans = save_retrans;
+		sm_res.retrans = save_retrans;
 	if (retry > 0)
-		_res.retry = save_retry;
+		sm_res.retry = save_retry;
 	return dr;
@@ -1578,7 +1595,7 @@ dns_addns(ns, port)
 		syserr("too many NameServers defined (%d max)", MAXNS);
-	_res.nsaddr_list[nsidx].sin_family = AF_INET;
-	_res.nsaddr_list[nsidx].sin_addr = *ns;
+	sm_res.nsaddr_list[nsidx].sin_family = AF_INET;
+	sm_res.nsaddr_list[nsidx].sin_addr = *ns;
 	if (port != 0)
-		_res.nsaddr_list[nsidx].sin_port = htons(port);
-	_res.nscount = ++nsidx;
+		sm_res.nsaddr_list[nsidx].sin_port = htons(port);
+	sm_res.nscount = ++nsidx;
 	if (tTd(8, 61))
@@ -1639,3 +1656,3 @@ nsportip(p)
 	{
-		if ((_res.options & RES_INIT) == 0)
+		if ((sm_res.options & RES_INIT) == 0)
 			(void) res_init();
