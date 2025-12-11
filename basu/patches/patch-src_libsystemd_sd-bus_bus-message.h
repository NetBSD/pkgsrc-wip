$NetBSD$

--- src/libsystemd/sd-bus/bus-message.h.orig	2022-12-16 10:13:02.000000000 +0000
+++ src/libsystemd/sd-bus/bus-message.h
@@ -3,6 +3,8 @@
 
 #ifdef __FreeBSD__
 #include <sys/endian.h>
+#elif defined(__NetBSD__)
+#include <endian.h>
 #else
 #include <byteswap.h>
 #endif
@@ -129,7 +131,7 @@ static inline bool BUS_MESSAGE_NEED_BSWA
         return m->header->endian != BUS_NATIVE_ENDIAN;
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define bswap_16 bswap16
 #define bswap_32 bswap32
 #define bswap_64 bswap64
