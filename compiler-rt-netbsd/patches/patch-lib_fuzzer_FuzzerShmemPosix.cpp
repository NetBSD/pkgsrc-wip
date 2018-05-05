$NetBSD$

--- lib/fuzzer/FuzzerShmemPosix.cpp.orig	2018-02-01 23:46:06.000000000 +0000
+++ lib/fuzzer/FuzzerShmemPosix.cpp
@@ -32,6 +32,8 @@ std::string SharedMemoryRegion::Path(con
 
 std::string SharedMemoryRegion::SemName(const char *Name, int Idx) {
   std::string Res(Name);
+  if (!Res.empty() && Res[0] != '/')
+    Res.insert(Res.begin(), '/');
   return Res + (char)('0' + Idx);
 }
 
@@ -52,7 +54,7 @@ bool SharedMemoryRegion::Create(const ch
   for (int i = 0; i < 2; i++) {
     sem_unlink(SemName(Name, i).c_str());
     Semaphore[i] = sem_open(SemName(Name, i).c_str(), O_CREAT, 0644, 0);
-    if (Semaphore[i] == (void *)-1)
+    if (Semaphore[i] == SEM_FAILED)
       return false;
   }
   IAmServer = true;
@@ -70,7 +72,7 @@ bool SharedMemoryRegion::Open(const char
     return false;
   for (int i = 0; i < 2; i++) {
     Semaphore[i] = sem_open(SemName(Name, i).c_str(), 0);
-    if (Semaphore[i] == (void *)-1)
+    if (Semaphore[i] == SEM_FAILED)
       return false;
   }
   IAmServer = false;
