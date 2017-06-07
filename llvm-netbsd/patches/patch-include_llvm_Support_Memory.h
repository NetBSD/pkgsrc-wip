$NetBSD$

--- include/llvm/Support/Memory.h.orig	2016-12-16 22:50:53.000000000 +0000
+++ include/llvm/Support/Memory.h
@@ -28,14 +28,16 @@ namespace sys {
   /// @brief Memory block abstraction.
   class MemoryBlock {
   public:
-    MemoryBlock() : Address(nullptr), Size(0) { }
-    MemoryBlock(void *addr, size_t size) : Address(addr), Size(size) { }
+    MemoryBlock() : Address(nullptr), SecondaryAddress(nullptr), Size(0) { }
+    MemoryBlock(void *addr, size_t size)
+        : Address(addr), SecondaryAddress(nullptr), Size(size) {}
     void *base() const { return Address; }
     size_t size() const { return Size; }
 
   private:
-    void *Address;    ///< Address of first byte of memory area
-    size_t Size;      ///< Size, in bytes of the memory area
+    void *Address;          ///< Address of first byte of memory area
+    void *SecondaryAddress; ///< Secondary address of first byte of memory area
+    size_t Size;            ///< Size, in bytes of the memory area
     friend class Memory;
   };
 
