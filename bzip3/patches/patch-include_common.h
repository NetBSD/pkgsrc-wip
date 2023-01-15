$NetBSD$

* Replace the bswap16 funtion with posix htons,
  the bwap16 function only swaped on little endian
  systems making it a htons.
  Fixes build on illumos with gcc 12 and removes
  bswap16 redefinition warning on NetBSD.

* Remove non-standard #warning directive, we expect c99
  so restrict is to be available

* Support compilers without prefetch instructions.
  prefetch is just for cache optimization so it is safe
  define prefetch and prefetchw to nothing, tested and
  the same output files as with it.

--- include/common.h.orig	2023-01-10 14:45:22.000000000 +0000
+++ include/common.h
@@ -25,6 +25,7 @@
 
 #include <inttypes.h>
 #include <stdint.h>
+#include <arpa/inet.h>
 
 typedef uint8_t u8;
 typedef uint16_t u16;
@@ -52,7 +53,6 @@ static void write_neutral_s32(u8 * data,
     #define RESTRICT __restrict
 #else
     #define RESTRICT restrict
-    #warning Your compiler, configuration or platform might not be supported.
 #endif
 
 #if defined(__has_builtin)
@@ -63,14 +63,6 @@ static void write_neutral_s32(u8 * data,
     #define HAS_BUILTIN_PREFECTCH
 #endif
 
-#if defined(__has_builtin)
-    #if __has_builtin(__builtin_bswap16)
-        #define HAS_BUILTIN_BSWAP16
-    #endif
-#elif defined(__GNUC__) && (((__GNUC__ == 4) && (__GNUC_MINOR__ >= 8)) || (__GNUC__ >= 5))
-    #define HAS_BUILTIN_BSWAP16
-#endif
-
 #if defined(HAS_BUILTIN_PREFECTCH)
     #define prefetch(address) __builtin_prefetch((const void *)(address), 0, 0)
     #define prefetchw(address) __builtin_prefetch((const void *)(address), 1, 0)
@@ -89,37 +81,8 @@ static void write_neutral_s32(u8 * data,
     #define prefetch(address) __prefetch2((const void *)(address), 1)
     #define prefetchw(address) __prefetch2((const void *)(address), 17)
 #else
-    #error Your compiler, configuration or platform is not supported.
-#endif
-
-#if !defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)
-    #if defined(_LITTLE_ENDIAN) || (defined(BYTE_ORDER) && defined(LITTLE_ENDIAN) && BYTE_ORDER == LITTLE_ENDIAN) || \
-        (defined(_BYTE_ORDER) && defined(_LITTLE_ENDIAN) && _BYTE_ORDER == _LITTLE_ENDIAN) ||                        \
-        (defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && __BYTE_ORDER == __LITTLE_ENDIAN) ||                    \
-        (defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
-        #define __LITTLE_ENDIAN__
-    #elif defined(_BIG_ENDIAN) || (defined(BYTE_ORDER) && defined(BIG_ENDIAN) && BYTE_ORDER == BIG_ENDIAN) || \
-        (defined(_BYTE_ORDER) && defined(_BIG_ENDIAN) && _BYTE_ORDER == _BIG_ENDIAN) ||                       \
-        (defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && __BYTE_ORDER == __BIG_ENDIAN) ||                   \
-        (defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
-        #define __BIG_ENDIAN__
-    #elif defined(_WIN32)
-        #define __LITTLE_ENDIAN__
-    #endif
-#endif
-
-#if defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)
-    #if defined(HAS_BUILTIN_BSWAP16)
-        #define bswap16(x) (__builtin_bswap16(x))
-    #elif defined(_MSC_VER) && !defined(__INTEL_COMPILER)
-        #define bswap16(x) (_byteswap_ushort(x))
-    #else
-        #define bswap16(x) ((u16)(x >> 8) | (u16)(x << 8))
-    #endif
-#elif !defined(__LITTLE_ENDIAN__) && defined(__BIG_ENDIAN__)
-    #define bswap16(x) (x)
-#else
-    #error Your compiler, configuration or platform is not supported.
+    #define prefetch(address)
+    #define prefetchw(address)
 #endif
 
 #endif
