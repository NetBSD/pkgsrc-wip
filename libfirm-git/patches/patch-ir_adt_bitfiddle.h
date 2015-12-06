$NetBSD$

--- ir/adt/bitfiddle.h.orig	2015-12-06 00:56:25.000000000 +0000
+++ ir/adt/bitfiddle.h
@@ -23,7 +23,7 @@
  * @param x A 32-bit word.
  * @return The number of bits set in x.
  */
-static inline uint32_t popcount(uint32_t x)
+static inline uint32_t my_popcount(uint32_t x)
 {
 #if defined(__GNUC__) && __GNUC__ >= 4
 	return __builtin_popcount(x);
