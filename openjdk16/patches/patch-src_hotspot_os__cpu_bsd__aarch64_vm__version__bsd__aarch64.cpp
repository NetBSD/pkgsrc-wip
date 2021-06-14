$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_vm__version__bsd__aarch64.cpp,v 1.1 2019/12/04 12:19:25 tnn Exp $

TODO processor feature detection for aarch64

--- src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp	2021-06-10 13:23:39.869832843 -0400
@@ -252,7 +252,7 @@
 }
 
 void VM_Version::get_os_cpu_info() {
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
   // READ_SPECIALREG is not available from userland on OpenBSD.
   // Hardcode these values to the "lowest common denominator"
   _cpu = CPU_IMPL_ARM;
