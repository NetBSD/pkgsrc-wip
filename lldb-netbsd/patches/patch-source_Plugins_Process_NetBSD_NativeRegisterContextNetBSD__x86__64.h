$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.h.orig	2016-12-17 13:23:23.784681789 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.h
@@ -0,0 +1,77 @@
+//===-- NativeRegisterContextNetBSD_x86_64.h ---------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#if defined(__x86_64__)
+
+#ifndef lldb_NativeRegisterContextNetBSD_x86_64_h
+#define lldb_NativeRegisterContextNetBSD_x86_64_h
+
+#include "Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h"
+#include "Plugins/Process/Utility/RegisterContext_x86.h"
+#include "Plugins/Process/Utility/lldb-x86-register-enums.h"
+
+namespace lldb_private {
+namespace process_netbsd {
+
+class NativeProcessNetBSD;
+
+class NativeRegisterContextNetBSD_x86_64 : public NativeRegisterContextNetBSD {
+public:
+  NativeRegisterContextNetBSD_x86_64(const ArchSpec &target_arch,
+                                    NativeThreadProtocol &native_thread,
+                                    uint32_t concrete_frame_idx);
+
+  uint32_t GetRegisterSetCount() const override;
+
+  const RegisterSet *GetRegisterSet(uint32_t set_index) const override;
+
+  uint32_t GetUserRegisterCount() const override;
+
+  Error ReadRegister(const RegisterInfo *reg_info,
+                     RegisterValue &reg_value) override;
+
+  Error WriteRegister(const RegisterInfo *reg_info,
+                      const RegisterValue &reg_value) override;
+
+  Error ReadAllRegisterValues(lldb::DataBufferSP &data_sp) override;
+
+  Error WriteAllRegisterValues(const lldb::DataBufferSP &data_sp) override;
+
+protected:
+  void *GetGPRBuffer() override { return &m_gpr_x86_64; }
+
+private:
+  // Private member types.
+  enum class XStateType { Invalid, FXSAVE, XSAVE };
+  enum class RegSet { gpr, fpu, avx, mpx };
+
+  // Info about register ranges.
+  struct RegInfo {
+    uint32_t num_registers;
+    uint32_t num_gpr_registers;
+  };
+
+  // Private member variables.
+  IOVEC m_iovec;
+  RegInfo m_reg_info;
+  uint64_t m_gpr_x86_64[k_num_gpr_registers_x86_64];
+  uint32_t m_fctrl_offset_in_userarea;
+
+  // Private member methods.
+  bool IsCPUFeatureAvailable(RegSet feature_code) const;
+
+  bool IsRegisterSetAvailable(uint32_t set_index) const;
+};
+
+} // namespace process_netbsd
+} // namespace lldb_private
+
+#endif // #ifndef lldb_NativeRegisterContextNetBSD_x86_64_h
+
+#endif defined(__x86_64__)
