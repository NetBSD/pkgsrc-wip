$NetBSD$

--- Source/bmalloc/bmalloc/bmalloc.h.orig	2025-10-29 10:13:26.667038658 +0000
+++ Source/bmalloc/bmalloc/bmalloc.h
@@ -210,7 +210,7 @@ inline size_t availableMemory()
     return bmalloc::availableMemory();
 }
     
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD) || BOS(NETBSD)
 inline size_t memoryFootprint()
 {
     return bmalloc::memoryFootprint();
