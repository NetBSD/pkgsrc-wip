$NetBSD$

Avoid division by zero on NetBSD, when arc4random_uniform(0) ends
up being called...

--- lib/dns/zone.c.orig	2025-10-23 18:46:39.034862846 +0000
+++ lib/dns/zone.c
@@ -1035,8 +1035,9 @@ static const char *dbargv_default[] = { 
 #define DNS_ZONE_JITTER_ADD(a, b, c)                                         \
 	do {                                                                 \
 		isc_interval_t _i;                                           \
-		uint32_t _j;                                                 \
-		_j = (b) - isc_random_uniform((b) / 4);                      \
+		uint32_t _j, _b = b;                                         \
+		if (_b < 4) { _b = 4; }					     \
+		_j = (_b) - isc_random_uniform((_b) / 4);                    \
 		isc_interval_set(&_i, _j, 0);                                \
 		if (isc_time_add((a), &_i, (c)) != ISC_R_SUCCESS) {          \
 			dns_zone_log(zone, ISC_LOG_WARNING,                  \
