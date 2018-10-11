$NetBSD$

--- lib/msan/tests/msan_test.cc.orig	2018-08-21 21:25:44.000000000 +0000
+++ lib/msan/tests/msan_test.cc
@@ -1934,12 +1934,14 @@ TEST(MemorySanitizer, remquof) {
   EXPECT_NOT_POISONED(quo);
 }
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, remquol) {
   int quo;
   long double res = remquof(29.0, 3.0, &quo);
   ASSERT_NE(0.0, res);
   EXPECT_NOT_POISONED(quo);
 }
+#endif
 
 TEST(MemorySanitizer, lgamma) {
   double res = lgamma(1.1);
@@ -1953,11 +1955,13 @@ TEST(MemorySanitizer, lgammaf) {
   EXPECT_NOT_POISONED(signgam);
 }
 
+#if !defined(__NetBSD__)
 TEST(MemorySanitizer, lgammal) {
   long double res = lgammal(1.1);
   ASSERT_NE(0.0, res);
   EXPECT_NOT_POISONED(signgam);
 }
+#endif
 
 TEST(MemorySanitizer, lgamma_r) {
   int sgn;
