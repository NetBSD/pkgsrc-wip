$NetBSD$

--- src/pulsecore/sample-util.h.orig	2015-12-05 22:03:14.000000000 +0000
+++ src/pulsecore/sample-util.h
@@ -55,7 +55,7 @@ void pa_deinterleave(const void *src, vo
 void pa_sample_clamp(pa_sample_format_t format, void *dst, size_t dstr, const void *src, size_t sstr, unsigned n);
 
 static inline int32_t pa_mult_s16_volume(int16_t v, int32_t cv) {
-#if __WORDSIZE == 64 || ((ULONG_MAX) > (UINT_MAX))
+#if HAVE_FAST_64BIT_OPERATIONS
     /* Multiply with 64 bit integers on 64 bit platforms */
     return (v * (int64_t) cv) >> 16;
 #else
