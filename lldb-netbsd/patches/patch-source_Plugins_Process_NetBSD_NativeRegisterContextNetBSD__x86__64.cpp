$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.cpp.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.cpp
@@ -114,7 +114,7 @@ NativeRegisterContextNetBSD_x86_64::Nati
     uint32_t concrete_frame_idx)
     : NativeRegisterContextNetBSD(native_thread, concrete_frame_idx,
                                   CreateRegisterInfoInterface(target_arch)),
-      m_gpr_x86_64() {}
+      m_gpr_x86_64(), m_fpr_x86_64(), m_dbr_x86_64() {}
 
 // CONSIDER after local and llgs debugging are merged, register set support can
 // be moved into a base x86-64 class with IsRegisterSetAvailable made virtual.
@@ -143,8 +143,20 @@ NativeRegisterContextNetBSD_x86_64::GetR
 
 int NativeRegisterContextNetBSD_x86_64::GetSetForNativeRegNum(
     int reg_num) const {
-  if (reg_num < lldb_fctrl_x86_64)
+  if (reg_num <= k_last_gpr_x86_64)
     return GPRegSet;
+  else if (reg_num <= k_last_fpr_x86_64)
+    return FPRegSet;
+  else if (reg_num <= k_last_avx_x86_64)
+    return -1; // AVX
+  else if (reg_num <= k_last_mpxr_x86_64)
+    return -1; // MPXR
+  else if (reg_num <= k_last_mpxc_x86_64)
+    return -1; // MPXC
+  else if (reg_num <= k_last_avx_x86_64)
+    return -1; // AVX
+  else if (reg_num <= lldb_dr7_x86_64)
+    return DBRegSet; // DBR
   else
     return -1;
 }
@@ -157,6 +169,9 @@ int NativeRegisterContextNetBSD_x86_64::
   case FPRegSet:
     ReadFPR();
     return 0;
+  case DBRegSet:
+    ReadDBR();
+    return 0;
   default:
     break;
   }
@@ -170,6 +185,9 @@ int NativeRegisterContextNetBSD_x86_64::
   case FPRegSet:
     WriteFPR();
     return 0;
+  case DBRegSet:
+    WriteDBR();
+    return 0;
   default:
     break;
   }
@@ -285,6 +303,16 @@ Error NativeRegisterContextNetBSD_x86_64
   case lldb_es_x86_64:
     reg_value = (uint64_t)m_gpr_x86_64.regs[_REG_ES];
     break;
+  case lldb_dr0_x86_64:
+  case lldb_dr1_x86_64:
+  case lldb_dr2_x86_64:
+  case lldb_dr3_x86_64:
+  case lldb_dr4_x86_64:
+  case lldb_dr5_x86_64:
+  case lldb_dr6_x86_64:
+  case lldb_dr7_x86_64:
+    reg_value = (uint64_t)m_dbr_x86_64.dr[reg - lldb_dr0_x86_64];
+    break;
   }
 
   return error;
@@ -400,6 +428,16 @@ Error NativeRegisterContextNetBSD_x86_64
   case lldb_es_x86_64:
     m_gpr_x86_64.regs[_REG_ES] = reg_value.GetAsUInt64();
     break;
+  case lldb_dr0_x86_64:
+  case lldb_dr1_x86_64:
+  case lldb_dr2_x86_64:
+  case lldb_dr3_x86_64:
+  case lldb_dr4_x86_64:
+  case lldb_dr5_x86_64:
+  case lldb_dr6_x86_64:
+  case lldb_dr7_x86_64:
+    m_dbr_x86_64.dr[reg - lldb_dr0_x86_64] = reg_value.GetAsUInt64();
+    break;
   }
 
   if (WriteRegisterSet(set) != 0)
@@ -480,4 +518,227 @@ Error NativeRegisterContextNetBSD_x86_64
   return error;
 }
 
+Error NativeRegisterContextNetBSD_x86_64::IsWatchpointHit(uint32_t wp_index,
+                                                         bool &is_hit) {
+  if (wp_index >= NumSupportedHardwareWatchpoints())
+    return Error("Watchpoint index out of range");
+  
+  RegisterValue reg_value;
+  const RegisterInfo *const reg_info =
+    GetRegisterInfoAtIndex(lldb_dr6_x86_64);
+  Error error = ReadRegister(reg_info, reg_value);
+  if (error.Fail()) {
+    is_hit = false;
+    return error;
+  } 
+    
+  uint64_t status_bits = reg_value.GetAsUInt64();
+   
+  is_hit = status_bits & (1 << wp_index);
+ 
+  return error;
+}
+
+Error NativeRegisterContextNetBSD_x86_64::GetWatchpointHitIndex(
+    uint32_t &wp_index, lldb::addr_t trap_addr) {
+  uint32_t num_hw_wps = NumSupportedHardwareWatchpoints();
+  for (wp_index = 0; wp_index < num_hw_wps; ++wp_index) {
+    bool is_hit;
+    Error error = IsWatchpointHit(wp_index, is_hit);
+    if (error.Fail()) {
+      wp_index = LLDB_INVALID_INDEX32;
+      return error;
+    } else if (is_hit) {
+      return error;
+    }
+  }
+  wp_index = LLDB_INVALID_INDEX32;
+  return Error();
+}
+
+Error NativeRegisterContextNetBSD_x86_64::IsWatchpointVacant(uint32_t wp_index,
+                                                            bool &is_vacant) {
+  if (wp_index >= NumSupportedHardwareWatchpoints())
+    return Error("Watchpoint index out of range");
+
+  RegisterValue reg_value;
+  const RegisterInfo *const reg_info =
+    GetRegisterInfoAtIndex(lldb_dr7_x86_64);
+  Error error = ReadRegister(reg_info, reg_value);
+  if (error.Fail()) {
+    is_vacant = false;
+    return error;
+  }
+     
+  uint64_t control_bits = reg_value.GetAsUInt64();
+
+  is_vacant = !(control_bits & (1 << (2 * wp_index)));
+ 
+  return error;
+}
+
+Error NativeRegisterContextNetBSD_x86_64::SetHardwareWatchpointWithIndex(
+    lldb::addr_t addr, size_t size, uint32_t watch_flags, uint32_t wp_index) {
+
+  if (wp_index >= NumSupportedHardwareWatchpoints())
+    return Error("Watchpoint index out of range");
+
+  // Read only watchpoints aren't supported on x86_64. Fall back to read/write
+  // waitchpoints instead.
+  // TODO: Add logic to detect when a write happens and ignore that watchpoint
+  // hit.
+  if (watch_flags == 0x2)
+    watch_flags = 0x3;
+     
+  if (watch_flags != 0x1 && watch_flags != 0x3)   
+    return Error("Invalid read/write bits for watchpoint");
+
+  if (size != 1 && size != 2 && size != 4 && size != 8)
+    return Error("Invalid size for watchpoint");
+ 
+  bool is_vacant;
+  Error error = IsWatchpointVacant(wp_index, is_vacant);
+  if (error.Fail())
+    return error;
+  if (!is_vacant)                                                                                                                     
+    return Error("Watchpoint index not vacant");
+
+  RegisterValue reg_value;
+  const RegisterInfo *const reg_info_dr7 =
+    GetRegisterInfoAtIndex(lldb_dr7_x86_64);
+  error = ReadRegister(reg_info_dr7, reg_value);
+  if (error.Fail())
+    return error;
+
+  // for watchpoints 0, 1, 2, or 3, respectively,
+  // set bits 1, 3, 5, or 7
+  uint64_t enable_bit = 1 << (2 * wp_index);
+
+  // set bits 16-17, 20-21, 24-25, or 28-29
+  // with 0b01 for write, and 0b11 for read/write
+  uint64_t rw_bits = watch_flags << (16 + 4 * wp_index);
+
+  // set bits 18-19, 22-23, 26-27, or 30-31
+  // with 0b00, 0b01, 0b10, or 0b11
+  // for 1, 2, 8 (if supported), or 4 bytes, respectively
+  uint64_t size_bits = (size == 8 ? 0x2 : size - 1) << (18 + 4 * wp_index);                                                           
+
+  uint64_t bit_mask = (0x3 << (2 * wp_index)) | (0xF << (16 + 4 * wp_index));
+
+  uint64_t control_bits = reg_value.GetAsUInt64() & ~bit_mask;
+
+  control_bits |= enable_bit | rw_bits | size_bits;
+
+  const RegisterInfo *const reg_info_drN =
+    GetRegisterInfoAtIndex(lldb_dr0_x86_64 + wp_index);
+  error = WriteRegister(reg_info_drN, RegisterValue(addr));
+  if (error.Fail())
+    return error;
+
+  error =
+      WriteRegister(reg_info_dr7, RegisterValue(control_bits));
+  if (error.Fail())
+    return error;
+
+  error.Clear();
+  return error;
+}
+
+bool NativeRegisterContextNetBSD_x86_64::ClearHardwareWatchpoint(
+    uint32_t wp_index) {
+  if (wp_index >= NumSupportedHardwareWatchpoints())
+    return false;
+
+  RegisterValue reg_value;
+    
+  // for watchpoints 0, 1, 2, or 3, respectively,
+  // clear bits 0, 1, 2, or 3 of the debug status register (DR6)
+  const RegisterInfo *const reg_info_dr6 =
+    GetRegisterInfoAtIndex(lldb_dr6_x86_64);
+  Error error = ReadRegister(reg_info_dr6, reg_value);
+  if (error.Fail())
+    return false;
+  uint64_t bit_mask = 1 << wp_index;
+  uint64_t status_bits = reg_value.GetAsUInt64() & ~bit_mask;
+  error = WriteRegister(reg_info_dr6, RegisterValue(status_bits));
+  if (error.Fail())
+    return false;
+ 
+  // for watchpoints 0, 1, 2, or 3, respectively,
+  // clear bits {0-1,16-19}, {2-3,20-23}, {4-5,24-27}, or {6-7,28-31}
+  // of the debug control register (DR7)
+  const RegisterInfo *const reg_info_dr7 =
+    GetRegisterInfoAtIndex(lldb_dr7_x86_64);
+  error = ReadRegister(reg_info_dr7, reg_value);
+  if (error.Fail())
+    return false;
+  bit_mask = (0x3 << (2 * wp_index)) | (0xF << (16 + 4 * wp_index));
+  uint64_t control_bits = reg_value.GetAsUInt64() & ~bit_mask;
+  return WriteRegister(reg_info_dr7, RegisterValue(control_bits))
+      .Success();
+}
+
+Error NativeRegisterContextNetBSD_x86_64::ClearAllHardwareWatchpoints() {
+  RegisterValue reg_value;
+
+  // clear bits {0-4} of the debug status register (DR6)
+  const RegisterInfo *const reg_info_dr6 =
+    GetRegisterInfoAtIndex(lldb_dr6_x86_64);
+  Error error = ReadRegister(reg_info_dr6, reg_value);
+  if (error.Fail())
+    return error;
+  uint64_t bit_mask = 0xF;
+  uint64_t status_bits = reg_value.GetAsUInt64() & ~bit_mask;
+  error = WriteRegister(reg_info_dr6, RegisterValue(status_bits));
+  if (error.Fail())
+    return error;
+ 
+  // clear bits {0-7,16-31} of the debug control register (DR7)
+  const RegisterInfo *const reg_info_dr7 =
+    GetRegisterInfoAtIndex(lldb_dr7_x86_64);
+  error = ReadRegister(reg_info_dr7, reg_value);
+  if (error.Fail())
+    return error;
+  bit_mask = 0xFF | (0xFFFF << 16);
+  uint64_t control_bits = reg_value.GetAsUInt64() & ~bit_mask;
+  return WriteRegister(reg_info_dr7, RegisterValue(control_bits));
+}
+
+uint32_t NativeRegisterContextNetBSD_x86_64::SetHardwareWatchpoint(
+    lldb::addr_t addr, size_t size, uint32_t watch_flags) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_WATCHPOINTS));
+  const uint32_t num_hw_watchpoints = NumSupportedHardwareWatchpoints();
+  for (uint32_t wp_index = 0; wp_index < num_hw_watchpoints; ++wp_index) {
+    bool is_vacant;
+    Error error = IsWatchpointVacant(wp_index, is_vacant);
+    if (is_vacant) {
+      error = SetHardwareWatchpointWithIndex(addr, size, watch_flags, wp_index);
+      if (error.Success())
+        return wp_index;
+    }
+    if (error.Fail() && log) {
+      log->Printf("NativeRegisterContextNetBSD_x86_64::%s Error: %s",
+                  __FUNCTION__, error.AsCString());
+    }
+  }
+  return LLDB_INVALID_INDEX32;
+}
+
+lldb::addr_t
+NativeRegisterContextNetBSD_x86_64::GetWatchpointAddress(uint32_t wp_index) {
+  if (wp_index >= NumSupportedHardwareWatchpoints())
+    return LLDB_INVALID_ADDRESS;
+  RegisterValue reg_value;
+  const RegisterInfo *const reg_info_drN =
+    GetRegisterInfoAtIndex(lldb_dr0_x86_64 + wp_index);
+  if (ReadRegister(reg_info_drN, reg_value).Fail())
+    return LLDB_INVALID_ADDRESS;
+  return reg_value.GetAsUInt64();
+}                                                                                                                                     
+
+uint32_t NativeRegisterContextNetBSD_x86_64::NumSupportedHardwareWatchpoints() {
+  // Available debug address registers: dr0, dr1, dr2, dr3
+  return 4;
+}
+
 #endif // defined(__x86_64__)
