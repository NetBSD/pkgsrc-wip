$NetBSD$

--- include/llvm/Support/Threading.h.orig	2017-02-02 23:04:55.000000000 +0000
+++ include/llvm/Support/Threading.h
@@ -60,19 +60,14 @@ namespace llvm {
 
   typedef std::once_flag once_flag;
 
-  /// This macro is the only way you should define your once flag for LLVM's
-  /// call_once.
-#define LLVM_DEFINE_ONCE_FLAG(flag) static once_flag flag
-
 #else
 
   enum InitStatus { Uninitialized = 0, Wait = 1, Done = 2 };
-  typedef volatile sys::cas_flag once_flag;
-
-  /// This macro is the only way you should define your once flag for LLVM's
-  /// call_once.
-#define LLVM_DEFINE_ONCE_FLAG(flag) \
-  static ::llvm::once_flag flag = ::llvm::Uninitialized
+  class once_flag {
+  public:
+    once_flag() : status(::llvm::Uninitialized) {};
+    volatile ::llvm::sys::cas_flag status;
+  };
 
 #endif
 
@@ -82,7 +77,7 @@ namespace llvm {
   /// \code
   ///   void foo() {...};
   ///   ...
-  ///   LLVM_DEFINE_ONCE_FLAG(flag);
+  ///   static once_flag flag;
   ///   call_once(flag, foo);
   /// \endcode
   ///
@@ -96,24 +91,24 @@ namespace llvm {
 #else
     // For other platforms we use a generic (if brittle) version based on our
     // atomics.
-    sys::cas_flag old_val = sys::CompareAndSwap(&flag, Wait, Uninitialized);
+    sys::cas_flag old_val = sys::CompareAndSwap(&flag.status, Wait, Uninitialized);
     if (old_val == Uninitialized) {
       std::forward<Function>(F)(std::forward<Args>(ArgList)...);
       sys::MemoryFence();
       TsanIgnoreWritesBegin();
-      TsanHappensBefore(&flag);
-      flag = Done;
+      TsanHappensBefore(&flag.status);
+      flag.status = Done;
       TsanIgnoreWritesEnd();
     } else {
       // Wait until any thread doing the call has finished.
-      sys::cas_flag tmp = flag;
+      sys::cas_flag tmp = flag.status;
       sys::MemoryFence();
       while (tmp != Done) {
-        tmp = flag;
+        tmp = flag.status;
         sys::MemoryFence();
       }
     }
-    TsanHappensAfter(&flag);
+    TsanHappensAfter(&flag.status);
 #endif
   }
 
