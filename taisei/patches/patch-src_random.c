$NetBSD$

Fix build with gcc-5.

--- src/random.c.orig	2012-08-10 14:42:54.000000000 +0000
+++ src/random.c
@@ -33,19 +33,19 @@ int tsrand_p(RandomState *rnd) {
 	return (uint32_t)((rnd->z << 16u) + rnd->w) % TSRAND_MAX;
 }
 
-inline void tsrand_seed(uint32_t seed) {
+void tsrand_seed(uint32_t seed) {
 	tsrand_seed_p(tsrand_current, seed);
 }
 
-inline int tsrand(void) {
+int tsrand(void) {
 	return tsrand_p(tsrand_current);
 }
 
-inline double frand(void) {
+double frand(void) {
 	return tsrand()/(double)TSRAND_MAX;
 }
 
-inline double nfrand(void) {
+double nfrand(void) {
 	return frand() * 2 - 1;
 }
 
@@ -96,21 +96,21 @@ void tsrand_fill_p(RandomState *rnd, int
 		tsrand_array[i] = tsrand_p(rnd);
 }
 
-inline void tsrand_fill(int amount) {
+void tsrand_fill(int amount) {
 	tsrand_fill_p(tsrand_current, amount);
 }
 
-inline int tsrand_a(int idx) {
+int tsrand_a(int idx) {
 	if(idx >= tsrand_array_elems || idx < 0)
 		errx(-1, "tsrand_a: index out of range (%i / %i)", idx, tsrand_array_elems);
 	return tsrand_array[idx];
 }
 
-inline double afrand(int idx) {
+double afrand(int idx) {
 	return tsrand_a(idx)/(double)TSRAND_MAX;
 }
 
-inline double anfrand(int idx) {
+double anfrand(int idx) {
 	return afrand(idx) * 2 - 1;
 }
 
