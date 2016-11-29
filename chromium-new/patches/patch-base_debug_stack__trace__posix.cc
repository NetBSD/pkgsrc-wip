$NetBSD$

--- base/debug/stack_trace_posix.cc.orig	2016-11-10 20:02:09.000000000 +0000
+++ base/debug/stack_trace_posix.cc
@@ -571,6 +571,10 @@ class SandboxSymbolizeHelper {
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if defined(OS_FREEBSD) || defined(OS_NETBSD)
+    // TODO (rene) avoid link error, implement something?
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -586,6 +590,7 @@ class SandboxSymbolizeHelper {
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
