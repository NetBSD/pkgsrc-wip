$NetBSD$

Add support for NetBSD.

--- src/btop_shared.hpp.orig	2024-03-03 12:20:17.449075852 +0000
+++ src/btop_shared.hpp
@@ -34,7 +34,7 @@ tab-size = 4
 #include <ifaddrs.h>
 // clang-format on
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 # include <kvm.h>
 #endif
 
@@ -93,7 +93,7 @@ namespace Shared {
 
 	extern long coreCount, page_size, clk_tck;
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 	struct KvmDeleter {
 		void operator()(kvm_t* handle) {
 			kvm_close(handle);
