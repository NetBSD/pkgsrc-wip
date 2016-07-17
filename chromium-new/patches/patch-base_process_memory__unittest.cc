$NetBSD$

--- base/process/memory_unittest.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/process/memory_unittest.cc
@@ -83,11 +83,11 @@ TEST(MemoryTest, AllocatorShimWorking) {
 }
 
 // Android doesn't implement set_new_handler, so we can't use the
-// OutOfMemoryTest cases. OpenBSD does not support these tests either.
+// OutOfMemoryTest cases. OpenBSD, FreeBSD and NetBSD do not support these tests either.
 // Don't test these on ASan/TSan/MSan configurations: only test the real
 // allocator.
 // Windows only supports these tests with the allocator shim in place.
-#if !defined(OS_ANDROID) && !defined(OS_OPENBSD) &&   \
+#if !defined(OS_ANDROID) && !defined(OS_BSD) &&   \
     !(defined(OS_WIN) && !defined(ALLOCATOR_SHIM)) && \
     !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
 
@@ -451,5 +451,5 @@ TEST_F(OutOfMemoryHandledTest, Unchecked
   EXPECT_TRUE(value_ == NULL);
 }
 #endif  // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
-#endif  // !defined(OS_ANDROID) && !defined(OS_OPENBSD) && !(defined(OS_WIN) &&
+#endif  // !defined(OS_ANDROID) && !defined(OS_BSD) && !(defined(OS_WIN) &&
         // !defined(ALLOCATOR_SHIM)) && !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
