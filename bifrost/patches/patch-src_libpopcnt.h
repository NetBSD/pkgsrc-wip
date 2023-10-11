$NetBSD$

# Collision with libc popcount64

--- src/libpopcnt.h.orig	2023-10-11 12:18:05.350259610 +0000
+++ src/libpopcnt.h
@@ -105,6 +105,8 @@
  * It uses 12 arithmetic operations, one of which is a multiply.
  * http://en.wikipedia.org/wiki/Hamming_weight#Efficient_implementation
  */
+
+#ifndef __NetBSD__	// Defined in libc
 static inline uint64_t popcount64(uint64_t x)
 {
   uint64_t m1 = 0x5555555555555555ll;
@@ -118,6 +120,7 @@ static inline uint64_t popcount64(uint64
 
   return (x * h01) >> 56;
 }
+#endif
 
 #if defined(HAVE_ASM_POPCNT) && \
     defined(__x86_64__)
