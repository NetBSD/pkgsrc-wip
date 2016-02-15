$NetBSD$

--- src/vm/win32threadpool.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/win32threadpool.cpp
@@ -2088,7 +2088,7 @@ DWORD __stdcall ThreadpoolMgr::intermedi
     if (offset_counter * offset_multiplier > PAGE_SIZE)
         offset_counter = 0;
 
-    (void)_alloca(offset_counter * offset_multiplier);
+    (void)Alloca(offset_counter * offset_multiplier);
 
     intermediateThreadParam* param = (intermediateThreadParam*)arg;
 
@@ -4539,7 +4539,7 @@ DWORD __stdcall ThreadpoolMgr::GateThrea
                                                   prevCPUInfo.usageBufferSize))
         return 0;
 
-    prevCPUInfo.usageBuffer = (SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION *)alloca(prevCPUInfo.usageBufferSize);
+    prevCPUInfo.usageBuffer = (SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION *)Alloca(prevCPUInfo.usageBufferSize);
     if (prevCPUInfo.usageBuffer == NULL)
         return 0;
 
