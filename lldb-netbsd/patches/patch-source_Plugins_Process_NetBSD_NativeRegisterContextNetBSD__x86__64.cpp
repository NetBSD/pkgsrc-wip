$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.cpp.orig	2016-12-17 13:23:23.784160224 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.cpp
@@ -0,0 +1,315 @@
+//===-- NativeRegisterContextNetBSD_x86_64.cpp ---------------*- C++ -*-===//
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
+#include "NativeRegisterContextNetBSD_x86_64.h"
+
+#include "lldb/Core/DataBufferHeap.h"
+#include "lldb/Core/Error.h"
+#include "lldb/Core/Log.h"
+#include "lldb/Core/RegisterValue.h"
+#include "lldb/Host/HostInfo.h"
+
+#include "Plugins/Process/Utility/RegisterContextNetBSD_x86_64.h"
+
+#include <sys/exec_elf.h>
+
+using namespace lldb_private;
+using namespace lldb_private::process_netbsd;
+
+// ----------------------------------------------------------------------------
+// Private namespace.
+// ----------------------------------------------------------------------------
+
+namespace {
+// x86 64-bit general purpose registers.
+static const uint32_t g_gpr_regnums_x86_64[] = {
+    lldb_rax_x86_64,    lldb_rbx_x86_64,    lldb_rcx_x86_64, lldb_rdx_x86_64,
+    lldb_rdi_x86_64,    lldb_rsi_x86_64,    lldb_rbp_x86_64, lldb_rsp_x86_64,
+    lldb_r8_x86_64,     lldb_r9_x86_64,     lldb_r10_x86_64, lldb_r11_x86_64,
+    lldb_r12_x86_64,    lldb_r13_x86_64,    lldb_r14_x86_64, lldb_r15_x86_64,
+    lldb_rip_x86_64,    lldb_rflags_x86_64, lldb_cs_x86_64,  lldb_fs_x86_64,
+    lldb_gs_x86_64,     lldb_ss_x86_64,     lldb_ds_x86_64,  lldb_es_x86_64,
+    lldb_eax_x86_64,    lldb_ebx_x86_64,    lldb_ecx_x86_64, lldb_edx_x86_64,
+    lldb_edi_x86_64,    lldb_esi_x86_64,    lldb_ebp_x86_64, lldb_esp_x86_64,
+    lldb_r8d_x86_64,  // Low 32 bits or r8
+    lldb_r9d_x86_64,  // Low 32 bits or r9
+    lldb_r10d_x86_64, // Low 32 bits or r10
+    lldb_r11d_x86_64, // Low 32 bits or r11
+    lldb_r12d_x86_64, // Low 32 bits or r12
+    lldb_r13d_x86_64, // Low 32 bits or r13
+    lldb_r14d_x86_64, // Low 32 bits or r14
+    lldb_r15d_x86_64, // Low 32 bits or r15
+    lldb_ax_x86_64,     lldb_bx_x86_64,     lldb_cx_x86_64,  lldb_dx_x86_64,
+    lldb_di_x86_64,     lldb_si_x86_64,     lldb_bp_x86_64,  lldb_sp_x86_64,
+    lldb_r8w_x86_64,  // Low 16 bits or r8
+    lldb_r9w_x86_64,  // Low 16 bits or r9
+    lldb_r10w_x86_64, // Low 16 bits or r10
+    lldb_r11w_x86_64, // Low 16 bits or r11
+    lldb_r12w_x86_64, // Low 16 bits or r12
+    lldb_r13w_x86_64, // Low 16 bits or r13
+    lldb_r14w_x86_64, // Low 16 bits or r14
+    lldb_r15w_x86_64, // Low 16 bits or r15
+    lldb_ah_x86_64,     lldb_bh_x86_64,     lldb_ch_x86_64,  lldb_dh_x86_64,
+    lldb_al_x86_64,     lldb_bl_x86_64,     lldb_cl_x86_64,  lldb_dl_x86_64,
+    lldb_dil_x86_64,    lldb_sil_x86_64,    lldb_bpl_x86_64, lldb_spl_x86_64,
+    lldb_r8l_x86_64,    // Low 8 bits or r8
+    lldb_r9l_x86_64,    // Low 8 bits or r9
+    lldb_r10l_x86_64,   // Low 8 bits or r10
+    lldb_r11l_x86_64,   // Low 8 bits or r11
+    lldb_r12l_x86_64,   // Low 8 bits or r12
+    lldb_r13l_x86_64,   // Low 8 bits or r13
+    lldb_r14l_x86_64,   // Low 8 bits or r14
+    lldb_r15l_x86_64,   // Low 8 bits or r15
+    LLDB_INVALID_REGNUM // register sets need to end with this flag
+};
+static_assert((sizeof(g_gpr_regnums_x86_64) / sizeof(g_gpr_regnums_x86_64[0])) -
+                      1 ==
+                  k_num_gpr_registers_x86_64,
+              "g_gpr_regnums_x86_64 has wrong number of register infos");
+
+// Number of register sets provided by this context.
+enum { k_num_extended_register_sets = 2, k_num_register_sets = 4 };
+
+// Register sets for x86 64-bit.
+static const RegisterSet g_reg_sets_x86_64[k_num_register_sets] = {
+    {"General Purpose Registers", "gpr", k_num_gpr_registers_x86_64,
+     g_gpr_regnums_x86_64}};
+}
+
+#define REG_CONTEXT_SIZE (GetRegisterInfoInterface().GetGPRSize())
+
+// ----------------------------------------------------------------------------
+// NativeRegisterContextNetBSD_x86_64 members.
+// ----------------------------------------------------------------------------
+
+static RegisterInfoInterface *
+CreateRegisterInfoInterface(const ArchSpec &target_arch) {
+  assert((HostInfo::GetArchitecture().GetAddressByteSize() == 8) &&
+         "Register setting path assumes this is a 64-bit host");
+  // X86_64 hosts know how to work with 64-bit and 32-bit EXEs using the
+  // x86_64 register context.
+  return new RegisterContextNetBSD_x86_64(target_arch);
+}
+
+NativeRegisterContextNetBSD_x86_64::NativeRegisterContextNetBSD_x86_64(
+    const ArchSpec &target_arch, NativeThreadProtocol &native_thread,
+    uint32_t concrete_frame_idx)
+    : NativeRegisterContextNetBSD(native_thread, concrete_frame_idx,
+                                 CreateRegisterInfoInterface(target_arch)),
+      m_reg_info(), m_gpr_x86_64() {
+  // Set up data about ranges of valid registers.
+  switch (target_arch.GetMachine()) {
+  case llvm::Triple::x86_64:
+    m_reg_info.num_registers = k_num_registers_x86_64;
+    m_reg_info.num_gpr_registers = k_num_gpr_registers_x86_64;
+    break;
+  default:
+    assert(false && "Unhandled target architecture.");
+    break;
+  }
+}
+
+// CONSIDER after local and llgs debugging are merged, register set support can
+// be moved into a base x86-64 class with IsRegisterSetAvailable made virtual.
+uint32_t NativeRegisterContextNetBSD_x86_64::GetRegisterSetCount() const {
+  uint32_t sets = 0;
+  for (uint32_t set_index = 0; set_index < k_num_register_sets; ++set_index) {
+    if (IsRegisterSetAvailable(set_index))
+      ++sets;
+  }
+
+  return sets;
+}
+
+uint32_t NativeRegisterContextNetBSD_x86_64::GetUserRegisterCount() const {
+  uint32_t count = 0;
+  for (uint32_t set_index = 0; set_index < k_num_register_sets; ++set_index) {
+    const RegisterSet *set = GetRegisterSet(set_index);
+    if (set)
+      count += set->num_registers;
+  }
+  return count;
+}
+
+const RegisterSet *
+NativeRegisterContextNetBSD_x86_64::GetRegisterSet(uint32_t set_index) const {
+  if (!IsRegisterSetAvailable(set_index))
+    return nullptr;
+
+  switch (GetRegisterInfoInterface().GetTargetArchitecture().GetMachine()) {
+  case llvm::Triple::x86_64:
+    return &g_reg_sets_x86_64[set_index];
+  default:
+    assert(false && "Unhandled target architecture.");
+    return nullptr;
+  }
+
+  return nullptr;
+}
+
+Error NativeRegisterContextNetBSD_x86_64::ReadRegister(
+    const RegisterInfo *reg_info, RegisterValue &reg_value) {
+  Error error;
+
+  if (!reg_info) {
+    error.SetErrorString("reg_info NULL");
+    return error;
+  }
+
+  const uint32_t reg = reg_info->kinds[lldb::eRegisterKindLLDB];
+  if (reg == LLDB_INVALID_REGNUM) {
+    // This is likely an internal register for lldb use only and should not be
+    // directly queried.
+    error.SetErrorStringWithFormat("register \"%s\" is an internal-only lldb "
+                                   "register, cannot read directly",
+                                   reg_info->name);
+    return error;
+  }
+
+  uint32_t full_reg = reg;
+  bool is_subreg = reg_info->invalidate_regs &&
+                   (reg_info->invalidate_regs[0] != LLDB_INVALID_REGNUM);
+
+  if (is_subreg) {
+    // Read the full aligned 64-bit register.
+    full_reg = reg_info->invalidate_regs[0];
+  }
+
+  error = ReadRegisterRaw(full_reg, reg_value);
+
+  if (error.Success()) {
+    // If our read was not aligned (for ah,bh,ch,dh), shift our returned value
+    // one byte to the right.
+    if (is_subreg && (reg_info->byte_offset & 0x1))
+      reg_value.SetUInt64(reg_value.GetAsUInt64() >> 8);
+
+    // If our return byte size was greater than the return value reg size,
+    // then
+    // use the type specified by reg_info rather than the uint64_t default
+    if (reg_value.GetByteSize() > reg_info->byte_size)
+      reg_value.SetType(reg_info);
+  }
+  return error;
+}
+
+Error NativeRegisterContextNetBSD_x86_64::WriteRegister(
+    const RegisterInfo *reg_info, const RegisterValue &reg_value) {
+  assert(reg_info && "reg_info is null");
+
+  const uint32_t reg_index = reg_info->kinds[lldb::eRegisterKindLLDB];
+  if (reg_index == LLDB_INVALID_REGNUM)
+    return Error("no lldb regnum for %s", reg_info && reg_info->name
+                                              ? reg_info->name
+                                              : "<unknown register>");
+
+  return WriteRegisterRaw(reg_index, reg_value);
+
+  return Error("failed - register wasn't recognized to be a GPR, "
+               "write strategy unknown");
+}
+
+Error NativeRegisterContextNetBSD_x86_64::ReadAllRegisterValues(
+    lldb::DataBufferSP &data_sp) {
+  Error error;
+
+  data_sp.reset(new DataBufferHeap(REG_CONTEXT_SIZE, 0));
+  if (!data_sp) {
+    error.SetErrorStringWithFormat(
+        "failed to allocate DataBufferHeap instance of size %" PRIu64,
+        REG_CONTEXT_SIZE);
+    return error;
+  }
+
+  error = ReadGPR();
+  if (error.Fail())
+    return error;
+
+  uint8_t *dst = data_sp->GetBytes();
+  if (dst == nullptr) {
+    error.SetErrorStringWithFormat("DataBufferHeap instance of size %" PRIu64
+                                   " returned a null pointer",
+                                   REG_CONTEXT_SIZE);
+    return error;
+  }
+
+  ::memcpy(dst, &m_gpr_x86_64, GetRegisterInfoInterface().GetGPRSize());
+  dst += GetRegisterInfoInterface().GetGPRSize();
+
+  RegisterValue value((uint64_t)-1);
+  const RegisterInfo *reg_info =
+      GetRegisterInfoInterface().GetDynamicRegisterInfo("orig_eax");
+  if (reg_info == nullptr)
+    reg_info = GetRegisterInfoInterface().GetDynamicRegisterInfo("orig_rax");
+
+  if (reg_info != nullptr)
+    return DoWriteRegisterValue(reg_info->byte_offset, reg_info->name, value);
+
+  return error;
+}
+
+Error NativeRegisterContextNetBSD_x86_64::WriteAllRegisterValues(
+    const lldb::DataBufferSP &data_sp) {
+  Error error;
+
+  if (!data_sp) {
+    error.SetErrorStringWithFormat(
+        "NativeRegisterContextNetBSD_x86_64::%s invalid data_sp provided",
+        __FUNCTION__);
+    return error;
+  }
+
+  if (data_sp->GetByteSize() != REG_CONTEXT_SIZE) {
+    error.SetErrorStringWithFormat(
+        "NativeRegisterContextNetBSD_x86_64::%s data_sp contained mismatched "
+        "data size, expected %" PRIu64 ", actual %" PRIu64,
+        __FUNCTION__, REG_CONTEXT_SIZE, data_sp->GetByteSize());
+    return error;
+  }
+
+  uint8_t *src = data_sp->GetBytes();
+  if (src == nullptr) {
+    error.SetErrorStringWithFormat("NativeRegisterContextNetBSD_x86_64::%s "
+                                   "DataBuffer::GetBytes() returned a null "
+                                   "pointer",
+                                   __FUNCTION__);
+    return error;
+  }
+  ::memcpy(&m_gpr_x86_64, src, GetRegisterInfoInterface().GetGPRSize());
+
+  error = WriteGPR();
+  if (error.Fail())
+    return error;
+
+  src += GetRegisterInfoInterface().GetGPRSize();
+
+  return error;
+}
+
+bool NativeRegisterContextNetBSD_x86_64::IsCPUFeatureAvailable(
+    RegSet feature_code) const {
+
+  switch (feature_code) {
+  case RegSet::gpr:
+    return true;
+  }
+  return false;
+}
+
+bool NativeRegisterContextNetBSD_x86_64::IsRegisterSetAvailable(
+    uint32_t set_index) const {
+  uint32_t num_sets = k_num_register_sets - k_num_extended_register_sets;
+
+  switch (static_cast<RegSet>(set_index)) {
+  }
+  return false;
+}
+
+#endif // defined(__x86_64__)
