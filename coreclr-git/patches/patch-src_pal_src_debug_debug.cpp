$NetBSD$

--- src/pal/src/debug/debug.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/debug/debug.cpp
@@ -1340,7 +1340,7 @@ ReadProcessMemory(
     lpBaseAddressAligned = (int*)((SIZE_T) lpBaseAddress & ~VIRTUAL_PAGE_MASK);
     offset = ((SIZE_T) lpBaseAddress & VIRTUAL_PAGE_MASK);
     char *data;
-    data = (char*)alloca(VIRTUAL_PAGE_SIZE);
+    data = (char*)Alloca(VIRTUAL_PAGE_SIZE);
     while (nSize > 0)
     {
         vm_size_t bytesRead;
