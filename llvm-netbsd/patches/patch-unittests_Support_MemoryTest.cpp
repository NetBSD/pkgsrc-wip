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
@@ -349,13 +348,13 @@ TEST_P(MappedMemoryTest, UnalignedNear) 
 
 // Note that Memory::MF_WRITE is not supported exclusively across
 // operating systems and architectures and can imply MF_READ|MF_WRITE
+// RWX mapping is not allowed on all operating systems (W^X restrictions)
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
