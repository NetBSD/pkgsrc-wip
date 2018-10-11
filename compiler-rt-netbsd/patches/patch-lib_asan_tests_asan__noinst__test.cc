$NetBSD$

--- lib/asan/tests/asan_noinst_test.cc.orig	2018-08-21 21:25:41.000000000 +0000
+++ lib/asan/tests/asan_noinst_test.cc
@@ -153,6 +153,7 @@ TEST(AddressSanitizer, QuarantineTest) {
   EXPECT_LT(i, max_i);
 }
 
+#if !defined(__NetBSD__)
 void *ThreadedQuarantineTestWorker(void *unused) {
   (void)unused;
   u32 seed = my_rand();
@@ -187,6 +188,7 @@ TEST(AddressSanitizer, ThreadedQuarantin
     EXPECT_LT(mmaped2 - mmaped1, 320U * (1 << 20));
   }
 }
+#endif
 
 void *ThreadedOneSizeMallocStress(void *unused) {
   (void)unused;
