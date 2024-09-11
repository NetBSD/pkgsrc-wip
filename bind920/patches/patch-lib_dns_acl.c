$NetBSD$

Apply the fix for
https://gitlab.isc.org/isc-projects/bind9/-/issues/4908
from
https://gitlab.isc.org/isc-projects/bind9/-/merge_requests/9458

--- lib/dns/acl.c.orig	2024-09-11 07:15:08.673927538 +0000
+++ lib/dns/acl.c
@@ -459,13 +459,25 @@ dns_aclelement_match(const isc_netaddr_t
 }
 
 static void
-dns__acl_destroy(dns_acl_t *dacl) {
-	unsigned int i;
-	dns_acl_port_transports_t *port_proto;
+dns__acl_destroy_port_transports(dns_acl_t *acl) {
+	dns_acl_port_transports_t *port_proto = NULL;
+	dns_acl_port_transports_t *next = NULL;
+	ISC_LIST_FOREACH_SAFE (acl->ports_and_transports, port_proto, link,
+			       next)
+	{
+		ISC_LIST_DEQUEUE(acl->ports_and_transports, port_proto, link);
+		isc_mem_put(acl->mctx, port_proto, sizeof(*port_proto));
+	}
+}
 
+static void
+dns__acl_destroy(dns_acl_t *dacl) {
 	INSIST(!ISC_LINK_LINKED(dacl, nextincache));
 
-	for (i = 0; i < dacl->length; i++) {
+	isc_refcount_destroy(&dacl->references);
+	dacl->magic = 0;
+
+	for (size_t i = 0; i < dacl->length; i++) {
 		dns_aclelement_t *de = &dacl->elements[i];
 		if (de->type == dns_aclelementtype_keyname) {
 			dns_name_free(&de->keyname, dacl->mctx);
@@ -484,18 +496,8 @@ dns__acl_destroy(dns_acl_t *dacl) {
 		dns_iptable_detach(&dacl->iptable);
 	}
 
-	port_proto = ISC_LIST_HEAD(dacl->ports_and_transports);
-	while (port_proto != NULL) {
-		dns_acl_port_transports_t *next = NULL;
-
-		next = ISC_LIST_NEXT(port_proto, link);
-		ISC_LIST_DEQUEUE(dacl->ports_and_transports, port_proto, link);
-		isc_mem_put(dacl->mctx, port_proto, sizeof(*port_proto));
-		port_proto = next;
-	}
+	dns__acl_destroy_port_transports(dacl);
 
-	isc_refcount_destroy(&dacl->references);
-	dacl->magic = 0;
 	isc_mem_putanddetach(&dacl->mctx, dacl, sizeof(*dacl));
 }
 
@@ -659,10 +661,21 @@ dns_aclenv_set(dns_aclenv_t *env, dns_ac
 	REQUIRE(DNS_ACL_VALID(localhost));
 	REQUIRE(DNS_ACL_VALID(localnets));
 
-	rcu_read_lock();
 	localhost = rcu_xchg_pointer(&env->localhost, dns_acl_ref(localhost));
 	localnets = rcu_xchg_pointer(&env->localnets, dns_acl_ref(localnets));
-	rcu_read_unlock();
+
+	/*
+	 * This function is called only during interface scanning, so blocking
+	 * a bit is acceptable. Wait until all ongoing attachments to old
+	 * 'localhost' and 'localnets' are finished before we can detach and
+	 * possibly destroy them.
+	 *
+	 * The problem here isn't the memory reclamation per se, but
+	 * the reference counting race - we need to wait for the
+	 * critical section to end before we decrement the value and
+	 * possibly destroy the acl objects.
+	 */
+	synchronize_rcu();
 
 	dns_acl_detach(&localhost);
 	dns_acl_detach(&localnets);
@@ -675,24 +688,34 @@ dns_aclenv_copy(dns_aclenv_t *target, dn
 
 	rcu_read_lock();
 
-	dns_acl_t *localhost = rcu_dereference(source->localhost);
+	/*
+	 * We need to acquire the reference inside the critical section.
+	 */
+
+	dns_acl_t *localhost = dns_acl_ref(rcu_dereference(source->localhost));
 	INSIST(DNS_ACL_VALID(localhost));
 
-	dns_acl_t *localnets = rcu_dereference(source->localnets);
+	dns_acl_t *localnets = dns_acl_ref(rcu_dereference(source->localnets));
 	INSIST(DNS_ACL_VALID(localnets));
 
-	localhost = rcu_xchg_pointer(&target->localhost,
-				     dns_acl_ref(localhost));
-	localnets = rcu_xchg_pointer(&target->localnets,
-				     dns_acl_ref(localnets));
+	rcu_read_unlock();
+
+	localhost = rcu_xchg_pointer(&target->localhost, localhost);
+	localnets = rcu_xchg_pointer(&target->localnets, localnets);
+
+	/*
+	 * This function is called only during (re)configuration, so blocking
+	 * a bit is acceptable.
+	 *
+	 * See the comment above in dns_aclenv_set() for more detail.
+	 */
+	synchronize_rcu();
 
 	target->match_mapped = source->match_mapped;
 #if defined(HAVE_GEOIP2)
 	target->geoip = source->geoip;
 #endif /* if defined(HAVE_GEOIP2) */
 
-	rcu_read_unlock();
-
 	dns_acl_detach(&localhost);
 	dns_acl_detach(&localnets);
 }
@@ -703,17 +726,14 @@ dns__aclenv_destroy(dns_aclenv_t *aclenv
 
 	aclenv->magic = 0;
 
-	rcu_read_lock();
-	dns_acl_t *localhost = rcu_xchg_pointer(&aclenv->localhost, NULL);
-	INSIST(DNS_ACL_VALID(localhost));
-
-	dns_acl_t *localnets = rcu_xchg_pointer(&aclenv->localnets, NULL);
-	INSIST(DNS_ACL_VALID(localnets));
-
-	rcu_read_unlock();
+	/*
+	 * The last reference to the aclenv has been detached, so nobody should
+	 * be reading from this aclenv.  We can destroy the localhost and
+	 * localnet directly without swapping the pointers.
+	 */
 
-	dns_acl_detach(&localhost);
-	dns_acl_detach(&localnets);
+	dns_acl_detach(&aclenv->localhost);
+	dns_acl_detach(&aclenv->localnets);
 
 	isc_mem_putanddetach(&aclenv->mctx, aclenv, sizeof(*aclenv));
 }
