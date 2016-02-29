$NetBSD$

--- src/pcm/interval.c.orig	2016-02-24 08:33:29.000000000 +0000
+++ src/pcm/interval.c
@@ -26,7 +26,7 @@
 #include <limits.h>
 #include "pcm_local.h"
 
-static inline void div64_32(u_int64_t *n, u_int32_t d, u_int32_t *rem)
+static inline void div64_32(uint64_t *n, uint32_t d, uint32_t *rem)
 {
 	*rem = *n % d;
 	*n /= d;
@@ -88,7 +88,7 @@ static inline unsigned int sub(unsigned 
 static inline unsigned int muldiv32(unsigned int a, unsigned int b,
 				    unsigned int c, unsigned int *r)
 {
-	u_int64_t n = (u_int64_t) a * b;
+	uint64_t n = (uint64_t) a * b;
 	if (c == 0) {
 		assert(n > 0);
 		*r = 0;
