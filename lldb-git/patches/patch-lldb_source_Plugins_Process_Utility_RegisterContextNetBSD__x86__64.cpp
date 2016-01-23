$NetBSD$

--- lldb/source/Plugins/Process/Utility/RegisterContextNetBSD_x86_64.cpp.orig	2016-01-23 13:46:39.000000000 +0000
+++ lldb/source/Plugins/Process/Utility/RegisterContextNetBSD_x86_64.cpp
@@ -0,0 +1,117 @@
+//===-- RegisterContextNetBSD_x86_64.cpp ----------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===---------------------------------------------------------------------===//
+
+#include <vector>
+#include "RegisterContextPOSIX_x86.h"
+#include "RegisterContextNetBSD_x86_64.h"
+
+using namespace lldb_private;
+using namespace lldb;
+
+// src/sys/arch/amd64/include/frame_regs.h
+typedef struct _GPR
+{
+    int64_t rdi;     /*  0 */
+    int64_t rsi;     /*  1 */
+    int64_t rdx;     /*  2 */
+    int64_t rcx;     /*  3 */
+    int64_t r8;      /*  4 */
+    int64_t r9;      /*  5 */
+    int64_t r10;     /*  6 */
+    int64_t r11;     /*  7 */
+    int64_t r12;     /*  8 */
+    int64_t r13;     /*  9 */
+    int64_t r14;     /* 10 */
+    int64_t r15;     /* 11 */
+    int64_t rbp;     /* 12 */
+    int64_t rbx;     /* 13 */
+    int64_t rax;     /* 14 */
+    int64_t gs;      /* 15 */
+    int64_t fs;      /* 16 */
+    int64_t es;      /* 17 */
+    int64_t ds;      /* 18 */
+    int64_t trapno;  /* 19 */
+    int64_t err;     /* 20 */
+    int64_t rip;     /* 21 */
+    int64_t cs;      /* 22 */
+    int64_t eflags;  /* 23 */
+    int64_t rsp;     /* 24 */
+    int64_t ss;      /* 25 */
+} GPR;
+
+struct DBG {
+};
+
+struct UserArea {
+};
+
+//---------------------------------------------------------------------------
+// Include RegisterInfos_x86_64 to declare our g_register_infos_x86_64 structure.
+//---------------------------------------------------------------------------
+#define DECLARE_REGISTER_INFOS_X86_64_STRUCT
+#include "RegisterInfos_x86_64.h"
+#undef DECLARE_REGISTER_INFOS_X86_64_STRUCT
+
+static std::vector<lldb_private::RegisterInfo>&
+GetSharedRegisterInfoVector ()
+{
+    static std::vector<lldb_private::RegisterInfo> register_infos;
+    return register_infos;
+}
+
+static const RegisterInfo *
+PrivateGetRegisterInfoPtr (const lldb_private::ArchSpec& target_arch)
+{
+    switch (target_arch.GetMachine())
+    {
+        case llvm::Triple::x86_64:
+            return g_register_infos_x86_64;
+        default:
+            assert(false && "Unhandled target architecture.");
+            return nullptr;
+    }
+}
+
+static uint32_t
+PrivateGetRegisterCount (const lldb_private::ArchSpec& target_arch)
+{
+    switch (target_arch.GetMachine())
+    {
+        case llvm::Triple::x86_64:
+            return static_cast<uint32_t> (sizeof (g_register_infos_x86_64) / sizeof (g_register_infos_x86_64 [0]));
+        default:
+            assert(false && "Unhandled target architecture.");
+            return 0;
+    }
+}
+
+RegisterContextNetBSD_x86_64::RegisterContextNetBSD_x86_64(const ArchSpec &target_arch) :
+    lldb_private::RegisterInfoInterface(target_arch),
+    m_register_info_p (PrivateGetRegisterInfoPtr (target_arch)),
+    m_register_count (PrivateGetRegisterCount (target_arch))
+{
+}
+
+size_t
+RegisterContextNetBSD_x86_64::GetGPRSize() const
+{
+    return sizeof(GPR);
+}
+
+const RegisterInfo *
+RegisterContextNetBSD_x86_64::GetRegisterInfo() const
+{
+    return m_register_info_p;
+}
+
+uint32_t
+RegisterContextNetBSD_x86_64::GetRegisterCount () const
+{
+    return m_register_count;
+}
