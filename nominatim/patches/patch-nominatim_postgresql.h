$NetBSD$

Add byteswap support on SunOS
--- nominatim/postgresql.h.orig	2018-08-26 15:35:08.000000000 +0000
+++ nominatim/postgresql.h
@@ -7,6 +7,11 @@
 #define PG_OID_INT8			20
 #define PG_OID_INT4			23
 
+#if defined(__sun)
+#include <endian.h>
+#define PGint32(x) (htobe32(x))
+#define PGint64(x) (htobe64(x))
+#else
 #if HAVE_BYTESWAP
 #include <byteswap.h>
 #define PG_BSWAP32(x) bswap_32(x)
@@ -34,6 +39,7 @@
 #else
 #error "Cannot determine byte order."
 #endif
+#endif
 
 const char *build_conninfo(const char *db, const char *username, const char *password, const char *host, const char *port);
 
