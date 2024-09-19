$NetBSD$

- Use more standard bswap_64() since __bswap_64() is not supported on
  musl-libc.

--- lib/netfilter/log.c.orig	2008-01-14 15:48:45.000000000 +0000
+++ lib/netfilter/log.c
@@ -18,6 +18,7 @@
  * @{
  */
 
+#include <byteswap.h>
 #include <sys/types.h>
 #include <linux/netfilter/nfnetlink_log.h>
 
@@ -36,7 +37,7 @@ static uint64_t ntohll(uint64_t x)
 #elif __BYTE_ORDER == __LITTLE_ENDIAN
 static uint64_t ntohll(uint64_t x)
 {
-	return __bswap_64(x);
+	return bswap_64(x);
 }
 #endif
 
