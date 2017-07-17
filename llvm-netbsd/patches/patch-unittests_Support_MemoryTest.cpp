$NetBSD$

--- unittests/Support/MemoryTest.cpp.orig	2017-07-17 18:00:15.718300975 +0000
+++ unittests/Support/MemoryTest.cpp
@@ -13,7 +13,14 @@
 #include <cstdlib>
 
 #if defined(__NetBSD__)
-#include <sys/mmap.h>
+#  include <sys/mman.h>
+#  if defined(PROT_MPROTECT)
+#    define NETBSD_WITH_MPROTECT 1
+#  else
+#    define NETBSD_WITH_MPROTECT 0
+#  endif
+#else
+#  define NETBSD_WITH_MPROTECT 0
 #endif
 
 using namespace llvm;
@@ -36,7 +43,7 @@ protected:
     case Memory::MF_WRITE:
     case Memory::MF_READ|Memory::MF_WRITE:
       return Memory::MF_READ|Memory::MF_WRITE;
-#if !(defined(__NetBSD__) && defined(PROT_MPROTECT))
+#if !NETBSD_WITH_MPROTECT
     case Memory::MF_READ|Memory::MF_EXEC:
     case Memory::MF_READ|Memory::MF_WRITE|Memory::MF_EXEC:
     case Memory::MF_EXEC:
@@ -204,6 +211,7 @@ TEST_P(MappedMemoryTest, EnabledWrite) {
   EXPECT_NE((void*)nullptr, M3.base());
   EXPECT_LE(4U * sizeof(int), M3.size());
 
+  {FILE *fp = fopen("/tmp/log.txt", "a");fprintf(fp, "%s() %s:%d Flags=%x getTestableEquivalent(Flags)=%x protectMappedMemory()=%s\n", __func__, __FILE__, __LINE__, Flags, getTestableEquivalent(Flags), Memory::protectMappedMemory(M1, getTestableEquivalent(Flags)) ? "TRUE" : "FALSE");fflush(fp);fclose(fp);}
   EXPECT_FALSE(Memory::protectMappedMemory(M1, getTestableEquivalent(Flags)));
   EXPECT_FALSE(Memory::protectMappedMemory(M2, getTestableEquivalent(Flags)));
   EXPECT_FALSE(Memory::protectMappedMemory(M3, getTestableEquivalent(Flags)));
@@ -359,9 +367,11 @@ unsigned MemoryFlags[] = {
 			   Memory::MF_READ,
 			   Memory::MF_WRITE,
 			   Memory::MF_READ|Memory::MF_WRITE,
+#if !NETBSD_WITH_MPROTECT
 			   Memory::MF_EXEC,
 			   Memory::MF_READ|Memory::MF_EXEC,
 			   Memory::MF_READ|Memory::MF_WRITE|Memory::MF_EXEC
+#endif
 			 };
 
 INSTANTIATE_TEST_CASE_P(AllocationTests,
