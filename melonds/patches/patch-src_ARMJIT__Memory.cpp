$NetBSD$

Support NetBSD and PaX MPROTECT.

Use the portable "#ifdef __APPLE__" code on !Linux.

This is now solved a different way upstream.

--- src/ARMJIT_Memory.cpp.orig	2020-12-25 13:42:23.000000000 +0000
+++ src/ARMJIT_Memory.cpp
@@ -157,6 +157,8 @@ static void SigsegvHandler(int sig, sigi
     desc.EmulatedFaultAddr = (u8*)info->si_addr - curArea;
     #ifdef __APPLE__
         desc.FaultPC = (u8*)context->uc_mcontext->__ss.__rip;
+    #elif defined __NetBSD__
+        desc.FaultPC = (u8*)context->uc_mcontext.__gregs[_REG_RIP];
     #else
         desc.FaultPC = (u8*)context->uc_mcontext.gregs[REG_RIP];
     #endif
@@ -176,6 +178,8 @@ static void SigsegvHandler(int sig, sigi
 #ifdef __x86_64__
         #ifdef __APPLE__
             context->uc_mcontext->__ss.__rip = (u64)desc.FaultPC;
+        #elif defined __NetBSD__
+            context->uc_mcontext.__gregs[_REG_RIP] = (u64)desc.FaultPC;
         #else
             context->uc_mcontext.gregs[REG_RIP] = (u64)desc.FaultPC;
         #endif
@@ -739,13 +743,13 @@ void Init()
         ioctl(fd, ASHMEM_SET_SIZE, MemoryTotalSize);
         MemoryFile = fd;
     }
-#elif defined(__APPLE__)
+#elif defined(__linux__)
+    MemoryFile = memfd_create("melondsfastmem", 0);
+#else
     char* fastmemPidName = new char[snprintf(NULL, 0, "melondsfastmem%d", getpid()) + 1];
     sprintf(fastmemPidName, "melondsfastmem%d", getpid());
     MemoryFile = shm_open(fastmemPidName, O_RDWR|O_CREAT, 0600);
     delete[] fastmemPidName;
-#else
-    MemoryFile = memfd_create("melondsfastmem", 0);
 #endif
     ftruncate(MemoryFile, MemoryTotalSize);
 
@@ -781,24 +785,21 @@ void DeInit()
     svcUnmapProcessCodeMemory(envGetOwnProcessHandle(), (u64)MemoryBaseCodeMem, (u64)MemoryBase, MemoryTotalSize);
     virtmemFree(MemoryBaseCodeMem, MemoryTotalSize);
     free(MemoryBase);
-#elif defined(__APPLE__)
-    char* fastmemPidName = new char[snprintf(NULL, 0, "melondsfastmem%d", getpid()) + 1];
-    sprintf(fastmemPidName, "melondsfastmem%d", getpid());
-    shm_unlink(fastmemPidName);
-    delete[] fastmemPidName;
 #elif defined(_WIN32)
     assert(UnmapViewOfFile(MemoryBase));
     CloseHandle(MemoryFile);
 
     RemoveVectoredExceptionHandler(ExceptionHandlerHandle);
-#else
+#elif defined(__linux__)
     sigaction(SIGSEGV, &OldSaSegv, nullptr);
-#ifdef __APPLE__
-    sigaction(SIGBUS, &OldSaBus, nullptr);
-#endif
 
     munmap(MemoryBase, MemoryTotalSize);
     close(MemoryFile);
+#else
+    char* fastmemPidName = new char[snprintf(NULL, 0, "melondsfastmem%d", getpid()) + 1];
+    sprintf(fastmemPidName, "melondsfastmem%d", getpid());
+    shm_unlink(fastmemPidName);
+    delete[] fastmemPidName;
 #endif
 }
 
