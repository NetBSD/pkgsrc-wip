$NetBSD$

Apply patch from https://gitlab.isc.org/isc-projects/bind9/-/issues/5198
to work around core dump observed there.

--- lib/dns/include/dns/zone.h.orig	2025-02-11 17:35:30.987333800 +0000
+++ lib/dns/include/dns/zone.h
@@ -1544,14 +1544,19 @@ dns_zone_getsourceaddr(dns_zone_t *zone)
  * \li	'zone' has a non-empty primaries list.
  */
 
-isc_sockaddr_t
-dns_zone_getprimaryaddr(dns_zone_t *zone);
+isc_result_t
+dns_zone_getprimaryaddr(dns_zone_t *zone, isc_sockaddr_t *dest);
 /*%<
- * Get the zone's current primary server.
+ * Get the zone's current primary server into '*dest'.
  *
  * Requires:
  * \li	'zone' to be a valid zone.
  * \li	'zone' has a non-empty primaries list.
+ * \li	'dest' != NULL.
+ *
+ * Returns:
+ *\li	#ISC_R_SUCCESS if the current primary server was found
+ *\li	#ISC_R_NOMORE if all the primaries failed during the last xfer
  */
 
 isc_time_t
