$NetBSD$

--- lib/asan/tests/asan_interface_test.cc.orig	2018-08-21 21:25:41.000000000 +0000
+++ lib/asan/tests/asan_interface_test.cc
@@ -102,6 +102,7 @@ TEST(AddressSanitizerInterface, GetHeapS
   }
 }
 
+#if !defined(__NetBSD__)
 static const size_t kManyThreadsMallocSizes[] = {5, 1UL<<10, 1UL<<14, 357};
 static const size_t kManyThreadsIterations = 250;
 static const size_t kManyThreadsNumThreads =
@@ -135,6 +136,7 @@ TEST(AddressSanitizerInterface, ManyThre
   // so we can't check for equality here.
   EXPECT_LT(after_test, before_test + (1UL<<20));
 }
+#endif
 
 static void DoDoubleFree() {
   int *x = Ident(new int);
