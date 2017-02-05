$NetBSD$

--- include/llvm/Support/Threading.h.orig	2017-02-05 03:45:42.682914655 +0000
+++ include/llvm/Support/Threading.h
@@ -67,7 +67,11 @@ namespace llvm {
 #else
 
   enum InitStatus { Uninitialized = 0, Wait = 1, Done = 2 };
-  typedef volatile sys::cas_flag once_flag;
+  class once_flag {
+  public:
+    once_flag() : status(::llvm::Uninitialized) {};
+    volatile ::llvm::sys::cas_flag status;
+  };
 
   /// This macro is the only way you should define your once flag for LLVM's
   /// call_once.
@@ -96,24 +100,24 @@ namespace llvm {
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
 
