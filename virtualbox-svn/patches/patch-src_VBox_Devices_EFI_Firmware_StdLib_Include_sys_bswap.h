$NetBSD$

--- src/VBox/Devices/EFI/Firmware/StdLib/Include/sys/bswap.h.orig	2016-03-04 19:27:23.000000000 +0000
+++ src/VBox/Devices/EFI/Firmware/StdLib/Include/sys/bswap.h
@@ -17,8 +17,8 @@ __BEGIN_DECLS
 uint16_t bswap16(uint16_t) __attribute__((__const__));
 uint32_t bswap32(uint32_t) __attribute__((__const__));
 #else
-uint16_t bswap16(uint16_t) __RENAME(__bswap16) __attribute__((__const__));
-uint32_t bswap32(uint32_t) __RENAME(__bswap32) __attribute__((__const__));
+uint16_t bswap16(uint16_t) /*__RENAME(__bswap16)*/ __attribute__((__const__));
+uint32_t bswap32(uint32_t) /*__RENAME(__bswap32)*/ __attribute__((__const__));
 #endif
 uint64_t bswap64(uint64_t) __attribute__((__const__));
 __END_DECLS
