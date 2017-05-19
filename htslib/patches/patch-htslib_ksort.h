$NetBSD$

--- htslib/ksort.h.orig	2017-05-19 15:11:35.000000000 +0000
+++ htslib/ksort.h
@@ -63,6 +63,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <stdint.h>
 
 typedef struct {
 	void *left, *right;
@@ -266,13 +267,21 @@ typedef struct {
 	}
 
 #define ks_mergesort(name, n, a, t) ks_mergesort_##name(n, a, t)
-#define ks_introsort(name, n, a) ks_introsort_##name(n, a)
+/* NetBSD has typedef __uint32_t uint32_t.  Pass name through another
+   level of expansion as done by KSORT_INIT_GENERIC so the cpp output
+   will match. Otherwise, we get undefined referencas. */
+#define __ks_introsort(name, n, a) ks_introsort_##name(n, a)
+#define ks_introsort(name, n, a) __ks_introsort(name,n, a)
 #define ks_combsort(name, n, a) ks_combsort_##name(n, a)
 #define ks_heapsort(name, n, a) ks_heapsort_##name(n, a)
 #define ks_heapmake(name, n, a) ks_heapmake_##name(n, a)
 #define ks_heapadjust(name, i, n, a) ks_heapadjust_##name(i, n, a)
 #define ks_ksmall(name, n, a, k) ks_ksmall_##name(n, a, k)
-#define ks_shuffle(name, n, a) ks_shuffle_##name(n, a)
+/* NetBSD has typedef __uint32_t uint32_t.  Pass name through another
+   level of expansion as done by KSORT_INIT_GENERIC so the cpp output
+   will match. Otherwise, we get undefined referencas. */
+#define __ks_shuffle(name, n, a) ks_shuffle_##name(n, a)
+#define ks_shuffle(name, n, a) __ks_shuffle(name,n, a)
 
 #define ks_lt_generic(a, b) ((a) < (b))
 #define ks_lt_str(a, b) (strcmp((a), (b)) < 0)
