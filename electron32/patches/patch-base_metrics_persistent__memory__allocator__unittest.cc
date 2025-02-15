$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/metrics/persistent_memory_allocator_unittest.cc.orig	2024-10-18 12:33:59.786263200 +0000
+++ base/metrics/persistent_memory_allocator_unittest.cc
@@ -140,11 +140,12 @@ TEST_F(PersistentMemoryAllocatorTest, Al
   ASSERT_TRUE(obj1);
   Reference block1 = allocator_->GetAsReference(obj1);
   ASSERT_NE(0U, block1);
-  EXPECT_NE(nullptr, allocator_->GetAsObject<TestObject1>(block1));
   EXPECT_EQ(nullptr, allocator_->GetAsObject<TestObject2>(block1));
-  EXPECT_LE(sizeof(TestObject1), allocator_->GetAllocSize(block1));
-  EXPECT_GT(sizeof(TestObject1) + kAllocAlignment,
-            allocator_->GetAllocSize(block1));
+  size_t alloc_size_1 = 0;
+  EXPECT_NE(nullptr,
+            allocator_->GetAsObject<TestObject1>(block1, &alloc_size_1));
+  EXPECT_LE(sizeof(TestObject1), alloc_size_1);
+  EXPECT_GT(sizeof(TestObject1) + kAllocAlignment, alloc_size_1);
   PersistentMemoryAllocator::MemoryInfo meminfo1;
   allocator_->GetMemoryInfo(&meminfo1);
   EXPECT_EQ(meminfo0.total, meminfo1.total);
@@ -180,11 +181,12 @@ TEST_F(PersistentMemoryAllocatorTest, Al
   ASSERT_TRUE(obj2);
   Reference block2 = allocator_->GetAsReference(obj2);
   ASSERT_NE(0U, block2);
-  EXPECT_NE(nullptr, allocator_->GetAsObject<TestObject2>(block2));
   EXPECT_EQ(nullptr, allocator_->GetAsObject<TestObject1>(block2));
-  EXPECT_LE(sizeof(TestObject2), allocator_->GetAllocSize(block2));
-  EXPECT_GT(sizeof(TestObject2) + kAllocAlignment,
-            allocator_->GetAllocSize(block2));
+  size_t alloc_size_2 = 0;
+  EXPECT_NE(nullptr,
+            allocator_->GetAsObject<TestObject2>(block2, &alloc_size_2));
+  EXPECT_LE(sizeof(TestObject2), alloc_size_2);
+  EXPECT_GT(sizeof(TestObject2) + kAllocAlignment, alloc_size_2);
   PersistentMemoryAllocator::MemoryInfo meminfo2;
   allocator_->GetMemoryInfo(&meminfo2);
   EXPECT_EQ(meminfo1.total, meminfo2.total);
@@ -965,10 +967,10 @@ TEST(FilePersistentMemoryAllocatorTest, 
       uint32_t type_id;
       Reference ref;
       while ((ref = iter.GetNext(&type_id)) != 0) {
+        size_t size = 0;
         const char* data = allocator.GetAsArray<char>(
-            ref, 0, PersistentMemoryAllocator::kSizeAny);
+            ref, 0, PersistentMemoryAllocator::kSizeAny, &size);
         uint32_t type = allocator.GetType(ref);
-        size_t size = allocator.GetAllocSize(ref);
         // Ensure compiler can't optimize-out above variables.
         (void)data;
         (void)type;
