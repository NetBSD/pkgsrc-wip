$NetBSD$

--- base/memory/shared_memory_region_unittest.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ base/memory/shared_memory_region_unittest.cc
@@ -188,10 +188,12 @@ TYPED_TEST(SharedMemoryRegionTest, MapAt
   std::tie(region, rw_mapping) = CreateMappedRegion<TypeParam>(kDataSize);
   ASSERT_TRUE(region.IsValid());
   ASSERT_TRUE(rw_mapping.IsValid());
+#if !defined(OS_BSD)
   off_t offset = kDataSize / 2;
   typename TypeParam::MappingType mapping =
       region.MapAt(offset, kDataSize - offset);
   EXPECT_FALSE(mapping.IsValid());
+#endif
 }
 
 TYPED_TEST(SharedMemoryRegionTest, MapZeroBytesFails) {
