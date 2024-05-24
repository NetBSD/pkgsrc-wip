$NetBSD$

- avoid conflict with NetBSD's popcount(3)

--- src/nvim/math.c.orig	2024-05-23 22:42:40.233527563 +0000
+++ src/nvim/math.c
@@ -78,7 +78,7 @@ int xctz(uint64_t x)
 }
 
 /// Count number of set bits in bit field.
-int popcount(uint64_t x)
+int spopcount64(uint64_t x)
 {
   // Use compiler builtin if possible.
 #if defined(__clang__) || defined(__GNUC__)
