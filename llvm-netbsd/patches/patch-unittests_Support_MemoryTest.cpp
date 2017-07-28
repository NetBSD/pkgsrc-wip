$NetBSD$

--- unittests/Support/MemoryTest.cpp.orig	2017-07-05 18:41:47.000000000 +0000
+++ unittests/Support/MemoryTest.cpp
@@ -33,9 +33,8 @@ protected:
     case Memory::MF_READ|Memory::MF_WRITE:
       return Memory::MF_READ|Memory::MF_WRITE;
     case Memory::MF_READ|Memory::MF_EXEC:
-    case Memory::MF_READ|Memory::MF_WRITE|Memory::MF_EXEC:
     case Memory::MF_EXEC:
-      return Memory::MF_READ|Memory::MF_WRITE|Memory::MF_EXEC;
+      return Memory::MF_READ|Memory::MF_EXEC;
     }
     // Default in case values are added to the enum, as required by some compilers
     return Memory::MF_READ|Memory::MF_WRITE;
@@ -181,14 +180,19 @@ TEST_P(MappedMemoryTest, MultipleWrite) 
 
 TEST_P(MappedMemoryTest, EnabledWrite) {
   std::error_code EC;
+
+  // W^R restriction
+  if (Flags & Memory::MF_EXEC)
+    return;
+
   MemoryBlock M1 = Memory::allocateMappedMemory(2 * sizeof(int), nullptr, Flags,
-                                                EC);
+                                                EC, getTestableEquivalent(Flags));
   EXPECT_EQ(std::error_code(), EC);
   MemoryBlock M2 = Memory::allocateMappedMemory(8 * sizeof(int), nullptr, Flags,
-                                                EC);
+                                                EC, getTestableEquivalent(Flags));
   EXPECT_EQ(std::error_code(), EC);
   MemoryBlock M3 = Memory::allocateMappedMemory(4 * sizeof(int), nullptr, Flags,
-                                                EC);
+                                                EC, getTestableEquivalent(Flags));
   EXPECT_EQ(std::error_code(), EC);
 
   EXPECT_NE((void*)nullptr, M1.base());
@@ -223,7 +227,7 @@ TEST_P(MappedMemoryTest, EnabledWrite) {
   EXPECT_FALSE(Memory::releaseMappedMemory(M3));
   EXPECT_EQ(6, y[6]);
 
-  MemoryBlock M4 = Memory::allocateMappedMemory(16, nullptr, Flags, EC);
+  MemoryBlock M4 = Memory::allocateMappedMemory(16, nullptr, Flags, EC, getTestableEquivalent(Flags));
   EXPECT_EQ(std::error_code(), EC);
   EXPECT_NE((void*)nullptr, M4.base());
   EXPECT_LE(16U, M4.size());
@@ -349,13 +353,13 @@ TEST_P(MappedMemoryTest, UnalignedNear) 
 
 // Note that Memory::MF_WRITE is not supported exclusively across
 // operating systems and architectures and can imply MF_READ|MF_WRITE
+// RWX mapping is not allowed (W^X restrictions)
 unsigned MemoryFlags[] = {
 			   Memory::MF_READ,
 			   Memory::MF_WRITE,
 			   Memory::MF_READ|Memory::MF_WRITE,
 			   Memory::MF_EXEC,
-			   Memory::MF_READ|Memory::MF_EXEC,
-			   Memory::MF_READ|Memory::MF_WRITE|Memory::MF_EXEC
+			   Memory::MF_READ|Memory::MF_EXEC
 			 };
 
 INSTANTIATE_TEST_CASE_P(AllocationTests,
