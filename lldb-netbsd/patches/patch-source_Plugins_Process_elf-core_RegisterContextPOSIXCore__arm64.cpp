$NetBSD$

--- source/Plugins/Process/elf-core/RegisterContextPOSIXCore_arm64.cpp.orig	2018-02-02 18:39:12.000000000 +0000
+++ source/Plugins/Process/elf-core/RegisterContextPOSIXCore_arm64.cpp
@@ -43,7 +43,14 @@ bool RegisterContextCorePOSIX_arm64::Wri
 bool RegisterContextCorePOSIX_arm64::ReadRegister(const RegisterInfo *reg_info,
                                                   RegisterValue &value) {
   lldb::offset_t offset = reg_info->byte_offset;
-  uint64_t v = m_gpr.GetMaxU64(&offset, reg_info->byte_size);
+  uint64_t v;
+
+  if (reg_info->byte_size == 16) {
+    v = m_gpr.GetMaxU64(&offset, 8);
+    v = m_gpr.GetMaxU64(&offset, 8);
+  } else {
+    v = m_gpr.GetMaxU64(&offset, reg_info->byte_size);
+  }
   if (offset == reg_info->byte_offset + reg_info->byte_size) {
     value = v;
     return true;
