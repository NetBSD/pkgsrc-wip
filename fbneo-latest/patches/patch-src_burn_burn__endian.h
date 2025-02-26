$NetBSD$

Add byte-order swapping functions for NetBSD big-endian platforms.

--- src/burn/burn_endian.h.orig	2025-02-25 21:25:30.524933178 +0000
+++ src/burn/burn_endian.h
@@ -57,6 +57,13 @@ typedef union
 #define BURN_ENDIAN_SWAP_INT16(x)				({uint16_t tt; __sthbrx(&tt, x); tt;})
 #define BURN_ENDIAN_SWAP_INT32(x)				({uint32_t tt; __stwbrx(&tt, x); tt;})
 #define NO_64BIT_BYTESWAP
+// NetBSD
+#elif defined(__NetBSD__)
+#include <machine/endian.h>
+#define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
+#define BURN_ENDIAN_SWAP_INT16(x)				(bswap16(x))
+#define BURN_ENDIAN_SWAP_INT32(x)				(bswap32(x))
+#define BURN_ENDIAN_SWAP_INT64(x)				(bswap64(x))
 // GC/Wii/WiiU
 //#elif defined(HW_RVL)
 //#define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
