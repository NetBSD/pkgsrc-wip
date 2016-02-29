$NetBSD$

--- src/pcm/mask_inline.h.orig	2016-02-24 08:33:29.000000000 +0000
+++ src/pcm/mask_inline.h
@@ -29,7 +29,7 @@
 #define MASK_OFS(i)	((i) >> 5)
 #define MASK_BIT(i)	(1U << ((i) & 31))
 
-MASK_INLINE unsigned int ld2(u_int32_t v)
+MASK_INLINE unsigned int ld2(uint32_t v)
 {
         unsigned r = 0;
 
@@ -54,7 +54,7 @@ MASK_INLINE unsigned int ld2(u_int32_t v
         return r;
 }
 
-MASK_INLINE unsigned int hweight32(u_int32_t v)
+MASK_INLINE unsigned int hweight32(uint32_t v)
 {
         v = (v & 0x55555555) + ((v >> 1) & 0x55555555);
         v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
@@ -75,7 +75,7 @@ MASK_INLINE void snd_mask_none(snd_mask_
 
 MASK_INLINE void snd_mask_any(snd_mask_t *mask)
 {
-	memset(mask, 0xff, MASK_SIZE * sizeof(u_int32_t));
+	memset(mask, 0xff, MASK_SIZE * sizeof(uint32_t));
 }
 
 MASK_INLINE int snd_mask_empty(const snd_mask_t *mask)
