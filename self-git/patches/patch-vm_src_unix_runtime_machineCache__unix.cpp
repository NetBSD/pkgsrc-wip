$NetBSD$

--- vm/src/unix/runtime/machineCache_unix.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/unix/runtime/machineCache_unix.cpp
@@ -83,6 +83,12 @@
 
   void MachineCache::flush_instruction_cache_range(void* s, void* e) {}
 
+# elif TARGET_OS_VERSION == NETBSD_VERSION \
+    && TARGET_ARCH       == I386_ARCH
+  void MachineCache::flush_instruction_cache_word(void* addr) { }
+
+  void MachineCache::flush_instruction_cache_range(void* s, void* e) {}
+
 # elif TARGET_OS_VERSION == SOLARIS_VERSION \
     && TARGET_ARCH       == I386_ARCH
 void MachineCache::flush_instruction_cache_word(void* addr) { }
