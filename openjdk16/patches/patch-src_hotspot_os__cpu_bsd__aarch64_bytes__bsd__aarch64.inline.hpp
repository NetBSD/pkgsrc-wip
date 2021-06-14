$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_bytes__bsd__aarch64.inline.hpp,v 1.1 2019/12/04 12:19:25 tnn Exp $

NetBSD/evbarm-aarch64 support

--- src/hotspot/os_cpu/bsd_aarch64/bytes_bsd_aarch64.inline.hpp.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/hotspot/os_cpu/bsd_aarch64/bytes_bsd_aarch64.inline.hpp	2021-06-10 13:20:31.700747930 -0400
@@ -34,6 +34,10 @@
   #define bswap_16(x) swap16(x)
   #define bswap_32(x) swap32(x)
   #define bswap_64(x) swap64(x)
+#elif defined(__NetBSD__)
+#  define bswap_16(x) bswap16(x)
+#  define bswap_32(x) bswap32(x)
+#  define bswap_64(x) bswap64(x)
 #endif
 
 // Efficient swapping of data bytes from Java byte
