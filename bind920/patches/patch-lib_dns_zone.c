$NetBSD$

Apply patch from https://gitlab.isc.org/isc-projects/bind9/-/issues/5198
to work around core dump observed there.

--- lib/dns/zone.c.orig	2025-02-11 17:35:31.021335759 +0000
+++ lib/dns/zone.c
@@ -18212,18 +18212,22 @@ dns_zone_getsourceaddr(dns_zone_t *zone)
 	return sourceaddr;
 }
 
-isc_sockaddr_t
-dns_zone_getprimaryaddr(dns_zone_t *zone) {
-	isc_sockaddr_t curraddr;
+isc_result_t
+dns_zone_getprimaryaddr(dns_zone_t *zone, isc_sockaddr_t *dest) {
+	isc_result_t result = ISC_R_NOMORE;
 
 	REQUIRE(DNS_ZONE_VALID(zone));
+	REQUIRE(dest != NULL);
 
 	LOCK_ZONE(zone);
 	INSIST(dns_remote_count(&zone->primaries) > 0);
-	curraddr = dns_remote_curraddr(&zone->primaries);
+	if (!dns_remote_done(&zone->primaries)) {
+		*dest = dns_remote_curraddr(&zone->primaries);
+		result = ISC_R_SUCCESS;
+	}
 	UNLOCK_ZONE(zone);
 
-	return curraddr;
+	return result;
 }
 
 isc_time_t
