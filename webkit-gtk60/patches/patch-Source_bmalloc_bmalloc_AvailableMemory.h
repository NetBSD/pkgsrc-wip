$NetBSD$

--- Source/bmalloc/bmalloc/AvailableMemory.h.orig	2024-08-19 06:28:40.235246200 +0000
+++ Source/bmalloc/bmalloc/AvailableMemory.h
@@ -32,7 +32,7 @@ namespace bmalloc {
 
 BEXPORT size_t availableMemory();
 
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD) || BOS(NETBSD)
 struct MemoryStatus {
     MemoryStatus(size_t memoryFootprint, double percentAvailableMemoryInUse)
         : memoryFootprint(memoryFootprint)
@@ -61,7 +61,7 @@ inline double percentAvailableMemoryInUs
 
 inline bool isUnderMemoryPressure()
 {
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD) || BOS(NETBSD)
     return percentAvailableMemoryInUse() > memoryPressureThreshold;
 #else
     return false;
