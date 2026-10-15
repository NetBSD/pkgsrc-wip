$NetBSD$

Add NetBSD support.

--- Modules/Core/Common/include/itkMemoryUsageObserver.h.orig	2026-10-15 16:04:13.817069347 +0000
+++ Modules/Core/Common/include/itkMemoryUsageObserver.h
@@ -157,7 +157,7 @@ class ITKCommon_EXPORT MemoryUsageObserver
   public SunSolarisMemoryUsageObserver
 #elif defined(__APPLE__)
   public MacOSXMemoryUsageObserver
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
   public SysResourceMemoryUsageObserver
 #else
   public MallinfoMemoryUsageObserver
