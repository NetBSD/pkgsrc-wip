$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/v8/src/codegen/arm/cpu-arm.cc.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/v8/src/codegen/arm/cpu-arm.cc
@@ -21,6 +21,10 @@
 
 #include "src/codegen/cpu-features.h"
 
+#if V8_OS_NETBSD
+#include <machine/sysarch.h>
+#endif
+
 namespace v8 {
 namespace internal {
 
@@ -34,6 +38,8 @@ V8_NOINLINE void CpuFeatures::FlushICach
   struct arm_sync_icache_args args = {
       .addr = reinterpret_cast<uintptr_t>(start), .len = size};
   sysarch(ARM_SYNC_ICACHE, reinterpret_cast<void*>(&args));
+#elif V8_OS_NETBSD
+  arm_sync_icache(reinterpret_cast<uintptr_t>(start), size);
 #else
   register uint32_t beg asm("r0") = reinterpret_cast<uint32_t>(start);
   register uint32_t end asm("r1") = beg + size;
