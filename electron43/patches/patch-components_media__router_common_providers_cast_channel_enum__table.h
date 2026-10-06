$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/media_router/common/providers/cast/channel/enum_table.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/media_router/common/providers/cast/channel/enum_table.h
@@ -366,7 +366,12 @@ class EnumTable {
 
  private:
 #ifdef ARCH_CPU_64_BITS
+#ifdef __cpp_lib_hardware_interference_size
   alignas(std::hardware_destructive_interference_size)
+#else
+  static constexpr std::size_t hardware_destructive_interference_size = 64;
+  alignas(hardware_destructive_interference_size)
+#endif
 #endif
       std::initializer_list<Entry> data_;
   bool is_sorted_;
