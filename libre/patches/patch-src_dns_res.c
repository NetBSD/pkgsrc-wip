$NetBSD: patch-src_dns_res.c,v 1.1 2014/08/17 10:57:07 thomasklausner Exp $

Fix NetBSD, from upstream.

--- src/dns/res.c.orig	2015-12-17 14:07:00.000000000 +0000
+++ src/dns/res.c
@@ -33,26 +33,28 @@
  */
 int get_resolv_dns(char *domain, size_t dsize, struct sa *nsv, uint32_t *n)
 {
+	struct __res_state state;
 	uint32_t i;
 	int ret, err;
 
-	ret = res_init();
+	memset(&state, 0, sizeof(state));
+	ret = res_ninit(&state);
 	if (0 != ret)
 		return ENOENT;
 
-	if (_res.dnsrch[0])
-		str_ncpy(domain, _res.dnsrch[0], dsize);
-	else if ((char *)_res.defdname)
-		str_ncpy(domain, _res.defdname, dsize);
+	if (state.dnsrch[0])
+		str_ncpy(domain, state.dnsrch[0], dsize);
+	else if (state.defdname)
+		str_ncpy(domain, state.defdname, dsize);
 
-	if (!_res.nscount) {
+	if (!state.nscount) {
 		err = ENOENT;
 		goto out;
 	}
 
 	err = 0;
-	for (i=0; i<min(*n, (uint32_t)_res.nscount) && !err; i++) {
-		struct sockaddr_in *addr = &_res.nsaddr_list[i];
+	for (i=0; i<min(*n, (uint32_t)state.nscount) && !err; i++) {
+		struct sockaddr_in *addr = &state.nsaddr_list[i];
 		err |= sa_set_sa(&nsv[i], (struct sockaddr *)addr);
 	}
 	if (err)
@@ -61,7 +63,7 @@ int get_resolv_dns(char *domain, size_t 
 	*n = i;
 
  out:
-	res_close();
+	res_nclose(&state);
 
 	return err;
 }
