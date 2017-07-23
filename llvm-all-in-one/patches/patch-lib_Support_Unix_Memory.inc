$NetBSD$

--- lib/Support/Unix/Memory.inc.orig	2017-07-05 18:38:14.000000000 +0000
+++ lib/Support/Unix/Memory.inc
@@ -102,6 +102,11 @@ Memory::allocateMappedMemory(size_t NumB
 
   int Protect = getPosixProtectionFlags(PFlags);
 
+#if defined(__NetBSD__) && defined(PROT_MPROTECT)
+  // This is required in order to grant additional protection bits
+  Protect |= PROT_MPROTECT(PROT_READ | PROT_WRITE | PROT_EXEC);
+#endif
+
   // Use any near hint and the page size to set a page-aligned starting address
   uintptr_t Start = NearBlock ? reinterpret_cast<uintptr_t>(NearBlock->base()) +
                                       NearBlock->size() : 0;
