$NetBSD$

--- src/vm/threads.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/threads.cpp
@@ -2847,7 +2847,7 @@ DWORD __stdcall Thread::intermediateThre
     if (m_offset_counter * offset_multiplier > PAGE_SIZE)
         m_offset_counter = 0;
 
-    (void)_alloca(m_offset_counter * offset_multiplier);
+    (void)Alloca(m_offset_counter * offset_multiplier);
 
     intermediateThreadParam* param = (intermediateThreadParam*)arg;
 
@@ -7661,7 +7661,7 @@ __declspec(noinline) void AllocateSomeSt
     const size_t size = 0x400;
 #endif  //_TARGET_X86_
 
-    INT8* mem = (INT8*)_alloca(size);
+    INT8* mem = (INT8*)Alloca(size);
     // Actually touch the memory we just allocated so the compiler can't
     // optimize it away completely.
     // NOTE: this assumes the stack grows down (towards 0).
