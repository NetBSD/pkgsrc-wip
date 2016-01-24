$NetBSD$

--- src/Native/gc/env/gcenv.interlocked.inl.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/gc/env/gcenv.interlocked.inl
@@ -193,7 +193,7 @@ __forceinline T Interlocked::CompareExch
     return (T)(TADDR)_InterlockedCompareExchange((long volatile *)(void* volatile *)destination, (long)(void*)exchange, (long)(void*)comparand);
 #endif
 #else
-    return (T)(TADDR)__sync_val_compare_and_swap((void* volatile *)destination, comparand, exchange);
+    return (T)(TADDR)__sync_val_compare_and_swap((void* volatile *)destination, comparand, reinterpret_cast<void*>(exchange));
 #endif
 }
 
