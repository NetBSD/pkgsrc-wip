$NetBSD$

# Portability

--- bit-basics.h.orig	2020-11-16 02:34:09.827273691 +0000
+++ bit-basics.h
@@ -58,12 +58,14 @@ static inline int trail0_128(bit128 b) {
     return trail0_64((bit64)b);
 }
 #endif
+/*
 static inline int popcount32(bit32 i) {
   return __builtin_popcount(i);
 }
 static inline int popcount64(bit64 i) {
   return __builtin_popcountll(i);
 }
+*/
 #if Has_128bit
 static inline int popcount128(bit128 i) {
   return popcount64((bit64)i) + popcount64((bit64)(i>>64));
